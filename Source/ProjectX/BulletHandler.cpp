// Fill out your copyright notice in the Description page of Project Settings.

#include "BulletHandler.h"


// Sets default values
ABulletHandler::ABulletHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABulletHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABulletHandler::Shoot()
{
}

void ABulletHandler::OnButtonPressed()
{
	UE_LOG(LogTemp, Warning,TEXT("shouldn't be here"))
}

void ABulletHandler::OnButtonHold()
{
}


