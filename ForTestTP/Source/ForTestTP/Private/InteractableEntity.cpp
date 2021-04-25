// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableEntity.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AInteractableEntity::AInteractableEntity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	center = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("Center"));
	RootComponent = center;

	shape = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Shape"));
	shape->SetupAttachment(center);

	isDetected = false;
}

// Called when the game starts or when spawned
void AInteractableEntity::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractableEntity::Interact() {
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Interact Activaty"));
}



