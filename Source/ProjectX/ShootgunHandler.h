// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BulletHandler.h"
#include "ShootgunHandler.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTX_API AShootgunHandler : public ABulletHandler
{
	
    GENERATED_BODY()
public:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
public:
    virtual void OnButtonPressed() override;
    virtual void OnButtonHold() override; 
	
	
};
