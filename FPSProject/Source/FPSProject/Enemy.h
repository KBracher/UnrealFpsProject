// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class FPSPROJECT_API AEnemy : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* Mesh1P;

private :
	float hp;
	float speed;
public:	
	// Sets default values for this actor's properties
	AEnemy();
	float getHp();
	void hurt(float val);
	void Death();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
