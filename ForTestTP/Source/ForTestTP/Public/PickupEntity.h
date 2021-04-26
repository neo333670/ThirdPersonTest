// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupEntity.generated.h"

UCLASS()
class FORTESTTP_API APickupEntity : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupEntity();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Mymesh;

	UPROPERTY(EditAnywhere)
	class USceneComponent* HoldingComp;
	
	bool bHolding;
	bool bGravity;

	class ACharacter* MyCharacter;
	class UCameraComponent* PlayerCamera;
	FVector ForwardVector;

	UFUNCTION()
		void Pickup();
};
