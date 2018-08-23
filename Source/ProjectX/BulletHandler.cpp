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
	UE_LOG(LogTemp, Warning, TEXT("you are using BaseBulletClass, you should use a class that inherits from it instead "))
}

void ABulletHandler::OnButtonPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("you are using BaseBulletClass, you should use a class that inherits from it instead "))
}

void ABulletHandler::OnButtonHold()
{
	UE_LOG(LogTemp, Warning, TEXT("you are using BaseBulletClass, you should use a class that inherits from it instead "))
}


//Adds bullets to the world and pool
void ABulletHandler::InitBulletsCount(int count)
{
    for (int i = 0; i < count; i ++) AddBullet();
}

ABaseBulletClass *ABulletHandler::AddBullet(){
    
    if(UWorld *World = GetWorld()){
    
        //Set Spawn Collision Handling Override
        FActorSpawnParameters ActorSpawnParams;
        ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
        
        ABaseBulletClass *bullet = World->SpawnActor<ABaseBulletClass>(BulletType, GetActorLocation(), FRotator::ZeroRotator, ActorSpawnParams);
        bulletPool.Add(bullet);
        
        return bullet;
        
    }; return nullptr;
    
}

//Use this funtion to get a bullet from the world
ABaseBulletClass *ABulletHandler::GetBullet(){
    
    for (int i = 0; i < bulletPool.Num(); i ++) {
        if(bulletPool[i]->inUse == false)return bulletPool[i];
    }; return nullptr;
    
}

void ABulletHandler::FireBullet(FRotator rotation)
{
        
    //Get bullet from pool
    if(ABaseBulletClass *getBullet = GetBullet()){
        
        //Reset bullet and activate it here
        getBullet->Start(GetActorLocation(),rotation);
        
    }else if(ABaseBulletClass *addBullet = AddBullet()){
        
        //Adding bullet object to our bullet pool
        addBullet->Start(GetActorLocation(),rotation);
        
    }
    
}
