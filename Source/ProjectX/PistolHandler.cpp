// Fill out your copyright notice in the Description page of Project Settings.

#include "PistolHandler.h"

// Called when the game starts or when spawned
void APistolHandler::BeginPlay()
{
	Super::BeginPlay();
    
    //Initelize bullet pool with count of 10
    InitBulletsCount(10);

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
			//Here we fire a bullet from the pool
            FireBullet(GetActorRotation());
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
            //Here we fire a bullet from the pool
            FireBullet(GetActorRotation());
			ShootTimer = CurrentGameTime+ShootDelay;
		}
	}
}
