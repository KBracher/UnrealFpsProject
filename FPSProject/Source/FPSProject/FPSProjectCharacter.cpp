// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSProjectCharacter.h"
#include "FPSProjectProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h" // for FXRMotionControllerBase::RightHandSourceId
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Enemy.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AFPSProjectCharacter

AFPSProjectCharacter::AFPSProjectCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));


	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	PrimaryActorTick.bCanEverTick = true;

}


void AFPSProjectCharacter::TakeDamage(int val)
{
	health -= val;
	if (health <= 0) {
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
}

void AFPSProjectCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor

	// Show or hide the two versions of the gun based on whether or not we're using motion controllers.
	
	Mesh1P->SetHiddenInGame(false, true);
	FActorSpawnParameters SpawnParams;
	//Actual Spawn. The following function returns a reference to the spawned actor

	AWeapon* w1 = GetWorld()->SpawnActor<AWeapon>(Weapon1, GetTransform(), SpawnParams);
	w1->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	AWeapon* w2 = GetWorld()->SpawnActor<AWeapon>(Weapon2, GetTransform(), SpawnParams);
	w2->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	AWeapon* w3 = GetWorld()->SpawnActor<AWeapon>(Weapon3, GetTransform(), SpawnParams);
	w3->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	w2->SetActorHiddenInGame(true);
	w3->SetActorHiddenInGame(true);

	w1->currentAmmo = w1->ammoMax;
	w2->currentAmmo = w2->ammoMax;
	w3->currentAmmo = w3->ammoMax;

	weapons.Add(w1);
	weapons.Add(w2);
	weapons.Add(w3);

	currentWeapon = w1;
}

//////////////////////////////////////////////////////////////////////////
// Input

void AFPSProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AFPSProjectCharacter::ToggleCrouch);

	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AFPSProjectCharacter::Reload);
	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSProjectCharacter::OnFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AFPSProjectCharacter::StopFire);

	PlayerInputComponent->BindAction("UseWeapon1", IE_Pressed, this, &AFPSProjectCharacter::TakeVandal);
	PlayerInputComponent->BindAction("UseWeapon2", IE_Pressed, this, &AFPSProjectCharacter::TakeDeagle);
	PlayerInputComponent->BindAction("UseWeapon3", IE_Pressed, this, &AFPSProjectCharacter::TakeRay);
	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSProjectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSProjectCharacter::MoveRight);

	
	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFPSProjectCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFPSProjectCharacter::LookUpAtRate);
}

void AFPSProjectCharacter::ToggleCrouch()
{
	if (GetCharacterMovement()->IsCrouching())
	{
		UnCrouch();
	}
	else
	{
		Crouch();
		GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	}
}


void AFPSProjectCharacter::TakeVandal()
{
	if (!isReloading) {
		currentWeapon = weapons[0];
		weapons[0]->SetActorHiddenInGame(false);
		weapons[1]->SetActorHiddenInGame(true);
		weapons[2]->SetActorHiddenInGame(true);
	}
	
}

void AFPSProjectCharacter::TakeDeagle()
{
	if (!isReloading) {
		currentWeapon = weapons[1];
		weapons[0]->SetActorHiddenInGame(true);
		weapons[1]->SetActorHiddenInGame(false);
		weapons[2]->SetActorHiddenInGame(true);
	}
}

void AFPSProjectCharacter::TakeRay()
{
	if (!isReloading) {
		currentWeapon = weapons[2];
		weapons[0]->SetActorHiddenInGame(true);
		weapons[1]->SetActorHiddenInGame(true);
		weapons[2]->SetActorHiddenInGame(false);
	}
}

void AFPSProjectCharacter::OnFire()
{
	// try and fire a projectile
	/*if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			
			
			const FRotator SpawnRotation = GetControlRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile at the muzzle
			World->SpawnActor<AFPSProjectProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			
		}
	}*/
	if (!isReloading) {
		if (currentWeapon->isAuto) {
			isFiring = true;
		}
		UWorld* const World = GetWorld();
		const FRotator SpawnRotation = GetControlRotation();
		UGameplayStatics::SpawnEmitterAtLocation(World, GunParticle, FP_MuzzleLocation->GetComponentLocation() + SpawnRotation.RotateVector(GunOffset));

		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		FHitResult Hit(ForceInit);


		FVector start = FirstPersonCameraComponent->GetComponentLocation();
		FVector forward = FirstPersonCameraComponent->GetForwardVector();
		FVector end = start + (forward * 5000.f);

		if (World->LineTraceSingleByChannel(Hit, start, end, ECollisionChannel::ECC_WorldDynamic, Params)) {
			AActor* ActorHit = Hit.GetActor();
			if (ActorHit) {
				UGameplayStatics::SpawnEmitterAtLocation(World, PParticle, Hit.Location);
				if (Cast<AEnemy>(ActorHit)) {
					(Cast<AEnemy>(ActorHit))->hurt(currentWeapon->damage);
				}
			}
		}

		currentWeapon->lastShot = GetGameTimeSinceCreation();

		// try and play the sound if specified
		if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}

		// try and play a firing animation if specified
		if (FireAnimation != nullptr)
		{
			// Get the animation object for the arms mesh
			UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
			if (AnimInstance != nullptr)
			{
				AnimInstance->Montage_Play(FireAnimation, 1.f);
			}
		}

		currentWeapon->currentAmmo--;
		if (currentWeapon->currentAmmo <= 0) {
			Reload();
		}
	}
}

void AFPSProjectCharacter::Reload() 
{
	if (!isReloading) {
		isReloading = true;
		FTimerHandle    handle;
		GetWorldTimerManager().SetTimer(handle, [this]() {
			currentWeapon->currentAmmo = currentWeapon->ammoMax;
			isReloading = false;
			}, currentWeapon->reloadTime, false);
	}
	
}

void AFPSProjectCharacter::StopFire()
{
	isFiring = false;
}

void AFPSProjectCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFPSProjectCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AFPSProjectCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFPSProjectCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

// Called every frame
void AFPSProjectCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isFiring && currentWeapon->fireRate + currentWeapon->lastShot <= GetGameTimeSinceCreation()) {
		OnFire();
	}
}