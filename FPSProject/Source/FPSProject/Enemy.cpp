// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "FPSProjectCharacter.h"
#include "FPSProjectGameMode.h"
#include "Components/CapsuleComponent.h"
#include <Runtime/Engine/Classes/Kismet/KismetMathLibrary.h>
// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	hp = 100;
	speed = 200;

}

float AEnemy::getHp()
{
	return hp;
}

void AEnemy::hurt(float val)
{
	hp -= val;
	if (hp <= 0) {
		Death();
	}
}



// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	
}


// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AFPSProjectCharacter* MyCharacter;
	MyCharacter = Cast<AFPSProjectCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (MyCharacter) {
		float Dirx = MyCharacter->GetActorLocation().X - this->GetActorLocation().X ;
		float DirY = MyCharacter->GetActorLocation().Y - this->GetActorLocation().Y;

		FVector dir =FVector(Dirx, DirY, 0.0f);
		if (abs(dir.X) + abs(dir.Y) <= 100 && lastAttack+attackSpeed <= GetGameTimeSinceCreation()) {
			Attack();
			lastAttack = GetGameTimeSinceCreation();
		}
		dir.Normalize();
		this->SetActorLocation(GetActorLocation() + dir * speed *DeltaTime);
	
	}
	
	
}

void AEnemy::Death()
{
	AFPSProjectGameMode* GameMode = (AFPSProjectGameMode*)GetWorld()->GetAuthGameMode();
	AFPSProjectCharacter* MyCharacter = Cast<AFPSProjectCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (MyCharacter) {
		MyCharacter->score += 100;
	}
	GameMode->UpdateEnemy();
	this->Destroy();
}

void AEnemy::Attack()
{
	AFPSProjectCharacter* MyCharacter = Cast<AFPSProjectCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	MyCharacter->TakeDamage(damage);
}
