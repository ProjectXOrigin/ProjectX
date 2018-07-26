// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectXProjectile.h"
#include "Components/SceneComponent.h"
#include "ProjectileHandler.generated.h"



USTRUCT()
struct FBulletPool
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnyWhere)
		TSubclassOf<AProjectXProjectile> BulletType;
	    UPROPERTY(EditAnyWhere)
		int BulletPoolSize;
		UPROPERTY(EditAnywhere)
		TArray<TSubclassOf<AProjectXProjectile>> BulletPool;
		UPROPERTY(EditAnyWhere)
		bool unlocked = true;
};



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

private:

	float mShootDelayTimer;
	int mBulletIndex = 0;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
		TArray<FBulletPool> Test;

	UPROPERTY(EditAnyWhere, Category = Projectile)
	TArray<TSubclassOf<class AProjectXProjectile>> Projectiles;

	TSubclassOf<class AProjectXProjectile> GetBullet();

	UPROPERTY(EditAnywhere,Category=ProjectileTimers)
	float mShootDelay;

	bool CanShoot();

	void OnMousePressed(FRotator _controllerRotation);

	void OnMouseHold(FRotator _controllerRotation);

	void OnMouseRelease(FRotator _controllerRotation);
	
	void ChangeProjectile(float _mouseScroolAxis);

};
