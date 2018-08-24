// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBulletClass.h" 

// Sets default values
ABaseBulletClass::ABaseBulletClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
    
    bulletVisuals = CreateDefaultSubobject<USphereComponent>(TEXT("BulletSphere"));
    bulletVisuals -> InitSphereRadius(12.0f);
    bulletVisuals -> BodyInstance.SetCollisionProfileName("Projectile");
    bulletVisuals -> OnComponentHit.AddDynamic(this, &ABaseBulletClass::OnHit);
    
    bulletVisuals->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.0f));
    bulletVisuals->CanCharacterStepUpOn = ECB_No;
    
    RootComponent = bulletVisuals;
    
    //Init the bullet movement here
    bulletMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
    
    bulletMovement->InitialSpeed = 10000.f;
    
    bulletMovement->MaxSpeed = 0.0f;
    bulletMovement->bRotationFollowsVelocity = true;
    bulletMovement->bShouldBounce = false;
    
    //Set the gravity to zero
    bulletMovement->ProjectileGravityScale = 0;
    
    //Deactivate tick here for pool
    bulletMovement->Deactivate();
    bulletMovement->SetComponentTickEnabled(false);
    //SetActorHiddenInGame(true);
    
    //The bullet is not in use when initelized
    inUse = false;
    
    //Initial life span of the bullet base class
    InitialLifeSpan = 0.0f;
    Lifetime = 3.0f;
    
}

// Called when the game starts or when spawned
void ABaseBulletClass::BeginPlay()
{
	Super::BeginPlay();
}

///////////////////////
//BaseBullet logic here
///////////////////////

//Init on hit function
void ABaseBulletClass::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    
    if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
    {
        OtherComponent->AddImpulseAtLocation(bulletMovement->Velocity * 100.0f, Hit.ImpactPoint);
    }
    
    //Disable actor
    Disable();
}

void ABaseBulletClass::Disable()
{
    
    //Clear timer here
    GetWorld()->GetTimerManager().ClearTimer(TimerHandle); 
    TimerDel = nullptr;
    
    // Hides visible components
    SetActorHiddenInGame(true);
    inUse = false;
    
}

//This function resets the actors projectile to the instace orgin
void ABaseBulletClass::Start(FVector location, FRotator rotator)
{
    
    //Set location for bullet and rotation here
    SetActorLocation(location);
    SetActorRotation(rotator);
    
    //Calculate velocity
    bulletMovement->UpdatedComponent = RootComponent;
    bulletMovement->Velocity = FVector(1.f,0.f,0.f);
    
    if (bulletMovement->Velocity.SizeSquared() > 0.f)
    {
        // InitialSpeed > 0 overrides initial velocity magnitude.
        if (bulletMovement->InitialSpeed > 0.f)bulletMovement->Velocity = bulletMovement->Velocity.GetSafeNormal() * bulletMovement->InitialSpeed;
        if (bulletMovement->bInitialVelocityInLocalSpace) bulletMovement->SetVelocityInLocalSpace(bulletMovement->Velocity);
        
    }
    
    bulletMovement->Activate();
    bulletMovement->SetComponentTickEnabled(true);
    
    //Setup deactive timer//Timer for deactivating bullet
    TimerDel.BindUFunction(this, FName("Disable"));
    GetWorldTimerManager().SetTimer(TimerHandle,TimerDel, Lifetime, false);
    
    // Hides visible components
    SetActorHiddenInGame(false);
    inUse = true;
    
}
