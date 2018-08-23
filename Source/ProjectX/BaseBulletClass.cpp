// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBulletClass.h" 

// Sets default values
ABaseBulletClass::ABaseBulletClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    
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
    
    bulletMovement->InitialSpeed = 10000.f;
    
    bulletMovement->MaxSpeed = 0.0f;
    bulletMovement->bRotationFollowsVelocity = true;
    bulletMovement->bShouldBounce = false;
    bulletMovement->ProjectileGravityScale = 0;
    
     UE_LOG(LogTemp, Warning, TEXT("hitt"))
    InitialLifeSpan = 0.0f;
     
}

// Called when the game starts or when spawned
void ABaseBulletClass::BeginPlay()
{
	Super::BeginPlay();
	
}

//Init on hit function
void ABaseBulletClass::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit){
   
    // Only add impulse and destroy projectile if we hit a physics
    if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
    {
        OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
        
        Destroy();
    }
    
}

