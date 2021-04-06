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

public:
	int nbWave ;
	TList<AEnemy>* enemies;
	AFPSProjectGameMode();

	virtual void Tick(float DeltaTime) override;
};



