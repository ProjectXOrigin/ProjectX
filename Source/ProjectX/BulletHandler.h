// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseBulletClass.h"
#include "BulletHandler.generated.h"

class AProjectXProjectile;

UCLASS()
class PROJECTX_API ABulletHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


    UFUNCTION(Category = "BulletHandler")
	virtual void Shoot();

	UPROPERTY(EditAnywhere, Category = "BulletHandler", meta = (ClampMin = "0.0") )
	float ShootDelay;
	float ShootTimer =0.f;



	UPROPERTY(EditAnyWhere, Category = "BulletHandler")
	TSubclassOf<ABaseBulletClass>  BulletType;


public:	

	virtual void OnButtonPressed();

	virtual void OnButtonHold();
	
	
};
