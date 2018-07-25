// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBulletClass.h" 

// Sets default values
ABaseBulletClass::ABaseBulletClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    bulletVisuals = CreateDefaultSubobject<USphereComponent>(TEXT("BulletSphere"));
    bulletVisuals -> InitSphereRadius(30.0f);
    bulletVisuals -> BodyInstance.SetCollisionProfileName("Projectile");
    bulletVisuals -> OnComponentHit.AddDynamic(this, &ABaseBulletClass::OnHit);
    
    bulletVisuals->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.0f));
    bulletVisuals->CanCharacterStepUpOn = ECB_No;
    
    RootComponent = bulletVisuals;
    
    //Init the bullet movement here
    bulletMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
    bulletMovement->UpdatedComponent = bulletVisuals;
    bulletMovement->InitialSpeed = 1000.f;
    
    bulletMovement->MaxSpeed = 0.0f;
    bulletMovement->bRotationFollowsVelocity = true;
    bulletMovement->bShouldBounce = false;
    
    InitialLifeSpan = 0.0f;
    
}

// Called when the game starts or when spawned
void ABaseBulletClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseBulletClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Init on hit function
void ABaseBulletClass::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit){
    
    
    
}

