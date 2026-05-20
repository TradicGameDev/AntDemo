// Sandwich.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sandwich.generated.h"

class USphereComponent;
class UStaticMeshComponent;

DECLARE_DYNAMIC_DELEGATE(FOnSandwichCollected);

UCLASS()
class ANTDEMO_API ASandwich : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASandwich();
	
	FOnSandwichCollected OnSandwichCollected;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sandwich")
	TObjectPtr<UStaticMeshComponent> SandwichMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sandwich")
	TObjectPtr<USphereComponent> CollisionSphere;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
