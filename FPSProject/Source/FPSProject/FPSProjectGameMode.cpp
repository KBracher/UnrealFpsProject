// Copyright Epic Games, Inc. All Rights Reserved.
#include "FPSProjectGameMode.h"
#include "FPSProjectHUD.h"
#include "FPSProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

AFPSProjectGameMode::AFPSProjectGameMode()
	: Super()
{
	PrimaryActorTick.bCanEverTick = true;

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSProjectHUD::StaticClass();


}

void AFPSProjectGameMode::UpdateEnemy()
{
	TSubclassOf<AEnemy> ClassToFind;
	ClassToFind = AEnemy::StaticClass();
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);
	if (FoundActors.Num() <= 1) {
		
		SpawnEnemy();
	}
}

void AFPSProjectGameMode::SpawnEnemy()
{
	FActorSpawnParameters SpawnParams;
	int x ;
	int y ;
	FVector Location ;
	FRotator Rotation ;
		
	for (int i = 0; i <= nbWave * nbSpawnWave; i++) {
		x = FMath::RandRange(-2000, 1500);
		y = FMath::RandRange(-1750, 1750);
		Location = FVector(x, y, 330);
		Rotation = FRotator(0, 0, 0);
		AActor* SAR = GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation, SpawnParams);		
	}
	nbWave++;
}

void AFPSProjectGameMode::BeginPlay()
{
	Super::BeginPlay();
	UpdateEnemy();
}


