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



void UProjectileHandler::OnMousePressed(FRotator _controllerRotation)
{
	FVector Spawnlocation = GetComponentLocation();
	FRotator SpawnRotator = _controllerRotation;

	FActorSpawnParameters ActorSpawnParams;

	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	UWorld* const world = GetWorld();

	world->SpawnActor<AProjectXProjectile>(ProjectileClass, Spawnlocation, SpawnRotator, ActorSpawnParams);

}

void UProjectileHandler::OnMouseHold(FRotator _controllerRotation)
{
	FVector Spawnlocation = GetComponentLocation();
	FRotator SpawnRotator = _controllerRotation;

	FActorSpawnParameters ActorSpawnParams;

	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

}

void UProjectileHandler::OnMouseRelease(FRotator _controllerRotation)
{
	FVector Spawnlocation = GetComponentLocation();
	FRotator SpawnRotator = _controllerRotation;

	FActorSpawnParameters ActorSpawnParams;

	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;


}

