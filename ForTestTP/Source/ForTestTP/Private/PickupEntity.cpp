// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupEntity.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
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
	MyCharacter->GetComponents(Components);

	if (Components.Num() > 0) {
		for (auto& Comp : Components) {
			if (Comp->GetName() == "HoldingComponent") {
				GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, TEXT("Finded"));
				HoldingComp = Cast<USceneComponent>(Comp);
			}
			//else { GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, TEXT("not Finded")); }
		}
	}
	else { GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, TEXT("Components.Num() == 0")); }
}

void APickupEntity::Pickup() {
	bGravity = !bGravity;
	bHolding = !bHolding;

	Mymesh->SetEnableGravity(bGravity);
	Mymesh->SetSimulatePhysics(bHolding ? false : true);
	Mymesh->SetCollisionEnabled(bHolding ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);

	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, UKismetStringLibrary::Conv_BoolToString(bHolding));

	if (HoldingComp && bHolding) {
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, TEXT("should be picked"));
		Mymesh->AttachToComponent(HoldingComp, FAttachmentTransformRules::KeepWorldTransform);
		SetActorLocation(HoldingComp->GetComponentLocation());
	}
	
	if (!bHolding) {
		Mymesh->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);		
	}
}

