// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectXProjectile.h"
#include "Components/SceneComponent.h"
#include "ProjectileHandler.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTX_API UProjectileHandler : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProjectileHandler();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnyWhere, Category = Projectile)
	TSubclassOf<class AProjectXProjectile> ProjectileClass;


	TSubclassOf<class AProjectXProjectile> GetBullet();


	void OnMousePressed(FRotator _controllerRotation);

	void OnMouseHold(FRotator _controllerRotation);

	void OnMouseRelease(FRotator _controllerRotation);
	
	
};
