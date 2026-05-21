// Sandwich.cpp

#include "Actors/Sandwich.h"
#include "Characters/PlayerCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ASandwich::ASandwich()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SandwichMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SandwichMesh"));
    SandwichMesh->SetupAttachment(GetRootComponent());

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
    CollisionSphere->SetupAttachment(SandwichMesh);

}

// Called when the game starts or when spawned
void ASandwich::BeginPlay()
{
    Super::BeginPlay();

    CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ASandwich::OnOverlapBegin);

}

void ASandwich::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (APlayerCharacter* PlayerRef = Cast<APlayerCharacter>(OtherActor))
    {
        OnSandwichCollected.Broadcast();
    }
}

// Called every frame
void ASandwich::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}