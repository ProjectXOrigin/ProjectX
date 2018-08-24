// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootgunHandler.h" 
#include "LogicOperations.h"

// Called when the game starts or when spawned
void AShootgunHandler::BeginPlay()
{
    Super::BeginPlay();
    
    //Initelize bullet pool with count of 10
    InitBulletsCount(10);
    
} 

//Logic for spreed
//Parameters spreed
//Spreed = 0.0f no spreed.
//Spreed more then 0 more spreed and more damage
void AShootgunHandler::FireSpreed(float spreed){
    
    //Fire normal bullet
    if(spreed == 0)FireBullet(GetActorRotation());
    
    //Initelize variables for determening how many bullets to add and what spreed span to use
    int count        = 15.0f * spreed;
    float spreedSpan = 35.0f * spreed;
    
    for (int i = 0; i < count; i++) {
      
        //Calculate new rotation vector and normalize the calculation
        FRotator rotator = FRotator(LogicOperations::Instance()->Normalize(GetActorRotation().Pitch - FMath::RandRange(-spreedSpan/2,spreedSpan/2), -180, 180)
                                    ,LogicOperations::Instance()->Normalize(GetActorRotation().Yaw  - FMath::RandRange(-spreedSpan/2,spreedSpan/2), -180, 180)
                                    ,LogicOperations::Instance()->Normalize(GetActorRotation().Roll - FMath::RandRange(-spreedSpan/2,spreedSpan/2), -180, 180)
        );
        
        //Fire bullet
        FireBullet(rotator);
        
    }
    
}

void AShootgunHandler::OnButtonPressed()
{
    UE_LOG(LogTemp, Warning, TEXT("Reached on Button Pressed"))
    if (UWorld* World = GetWorld())
    {
        
        UE_LOG(LogTemp, Warning, TEXT("Found World"))
        float CurrentGameTime = World->GetRealTimeSeconds();
        if (ShootTimer < CurrentGameTime)
        {
            //Here we fire a bullet from the pool
            FireSpreed(1.0f);
            
            ShootTimer = ShootDelay + CurrentGameTime;
        }
    }
}

void AShootgunHandler::OnButtonHold()
{
    
    UE_LOG(LogTemp,Warning,TEXT("Reached onButtonHold"))
    
    if (UWorld* World = GetWorld())
    {
        float CurrentGameTime = World->GetRealTimeSeconds();
        if (ShootTimer < CurrentGameTime)
        {
            //Here we fire a bullet from the pool
            FireSpreed(1.0f);
            ShootTimer = CurrentGameTime+ShootDelay;
        }
    }
}


