// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupEntity.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values
APickupEntity::APickupEntity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mymesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	Mymesh->SetSimulatePhysics(true);
	RootComponent = Mymesh;

	bHolding = false;
	bGravity = true;
}

// Called when the game starts or when spawned
void APickupEntity::BeginPlay()
{
	Super::BeginPlay();
	
	MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	PlayerCamera = MyCharacter->FindComponentByClass<UCameraComponent>();
	
	TArray<USceneComponent*> Components;

	if (Components.Num() > 0) {
		for (auto& Comp : Components) {
			if (Comp->GetName() == "HoldingComponent") {
				HoldingComp = Cast<USceneComponent>(Comp);
			}
		}

	}
}

void APickupEntity::Pickup() {}

