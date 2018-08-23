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
			
			

			World->SpawnActor<ABaseBulletClass>(BulletType, GetActorLocation(), GetActorRotation(), ActorSpawnParams);


			ShootTimer = ShootDelay + CurrentGameTime;
		}
	}
}

void APistolHandler::OnButtonHold()
{

	UE_LOG(LogTemp,Warning,TEXT("Reached onButtonHold"))

	if (UWorld* World = GetWorld())
	{
		float CurrentGameTime = World->GetRealTimeSeconds();
		if (ShootTimer < CurrentGameTime)
		{



			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;


			//World->SpawnActor<ABaseBulletClass>(BulletType, GetActorLocation(), GetActorRotation(), ActorSpawnParams);


			ShootTimer = CurrentGameTime+ShootDelay;
		}
	}
}
