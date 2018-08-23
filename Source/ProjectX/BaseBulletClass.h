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
   
    UPROPERTY(EditAnywhere,BlueprintReadWrite)
    UProjectileMovementComponent *bulletMovement;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    USphereComponent *bulletVisuals;
    
    
protected:
    
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    void GenerateProjectileMovment();

public:
    
    bool inUse;
    void Disable();
    void Start(FVector location, FRotator rotator);
    
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	
};
