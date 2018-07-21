// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileHandler.h"
#include "Runtime/Engine/Classes/Engine/World.h"


// Sets default values for this component's properties
UProjectileHandler::UProjectileHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UProjectileHandler::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProjectileHandler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}





TSubclassOf<class AProjectXProjectile> UProjectileHandler::GetBullet()
{
	
	return Projectiles[mBulletIndex];
}

bool UProjectileHandler::CanShoot()
{
	if (mShootDelayTimer > GetWorld()->TimeSeconds)
	{
		return false;
	}
	else
	{
		mShootDelayTimer = GetWorld()->TimeSeconds + mShootDelay;
		return true;
	}
}

void UProjectileHandler::OnMousePressed(FRotator _controllerRotation)
{
	

}

void UProjectileHandler::OnMouseHold(FRotator _controllerRotation)
{
}

void UProjectileHandler::OnMouseRelease(FRotator _controllerRotation)
{
}

void UProjectileHandler::ChangeProjectile(float _mouseScroolAxis)
{
	if (_mouseScroolAxis >0)
	{
		mBulletIndex++;
	}
	else if(_mouseScroolAxis < 0)
	{
		mBulletIndex--;
	}

	mBulletIndex = fmod(mBulletIndex, Projectiles.Num());
}

