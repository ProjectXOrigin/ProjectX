// Fill out your copyright notice in the Description page of Project Settings.

#include "PistolHandler.h"
#include "Engine/World.h"
#include "ProjectXProjectile.h"

// Called when the game starts or when spawned
void APistolHandler::BeginPlay()
{
	Super::BeginPlay();

}

void APistolHandler::OnButtonPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Reached on Button Pressed"))
	if (UWorld* World = GetWorld())
	{

		UE_LOG(LogTemp, Warning, TEXT("Found World"))
		float CurrentGameTime = World->GetRealTimeSeconds();
		if (ShootTimer < CurrentGameTime)
		{
			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
			
			UE_LOG(LogTemp, Warning, TEXT("spawnBullet"))

			World->SpawnActor<AProjectXProjectile>(BulletType, GetActorLocation(), GetActorRotation(), ActorSpawnParams);


			ShootTimer = ShootDelay+ CurrentGameTime;
		}
	}
}

void APistolHandler::OnButtonHold()
{
	if (UWorld* World = GetWorld())
	{
		float CurrentGameTime = World->GetRealTimeSeconds();
		if (ShootTimer < CurrentGameTime)
		{
			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;


			World->SpawnActor<AProjectXProjectile>(BulletType, GetActorLocation(), GetActorRotation(), ActorSpawnParams);


			ShootTimer += CurrentGameTime;
		}
	}
}