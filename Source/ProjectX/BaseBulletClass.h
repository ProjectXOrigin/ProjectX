// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/PrimitiveComponent.h"
#include "BaseBulletClass.generated.h"

UCLASS()
class PROJECTX_API ABaseBulletClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
    ABaseBulletClass();
    
    //Speed of the bullet
    float Speed;
   
    UProjectileMovementComponent *bulletMovement;
    USphereComponent *bulletVisuals;
    
    
protected:
    
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
    
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit); 
	
};
