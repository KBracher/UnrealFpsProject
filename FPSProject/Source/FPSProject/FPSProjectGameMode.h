// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Enemy.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSProjectGameMode.generated.h"

UCLASS(minimalapi)
class AFPSProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = Spawning)
	TSubclassOf<AActor> ActorToSpawn;

public:
	int nbWave = 0;
	int nbSpawnWave = 1;
	AFPSProjectGameMode();

	virtual void BeginPlay() override;
	void UpdateEnemy();
	void SpawnEnemy();
	


};



