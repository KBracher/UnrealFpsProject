// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class FPSPROJECT_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	UPROPERTY(EditDefaultsOnly, Category = WeaponProperty)
	float damage;

	UPROPERTY(EditDefaultsOnly, Category = WeaponProperty)
	bool isAuto;

	UPROPERTY(EditDefaultsOnly, Category = WeaponProperty)
	float reloadTime;

	UPROPERTY(EditDefaultsOnly, Category = WeaponProperty)
	int barrelSize;

	UPROPERTY(EditDefaultsOnly, Category = WeaponProperty)
	float fireRate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
