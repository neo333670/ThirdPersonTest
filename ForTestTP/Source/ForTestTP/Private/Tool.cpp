// Fill out your copyright notice in the Description page of Project Settings.


#include "Tool.h"


void ATool::BeginPlay() {
	Super::BeginPlay();

	intialPos = this->GetActorLocation();
}

void ATool::Pickup() {
	bGravity = !bGravity;
	bHolding = !bHolding;

	Mymesh->SetEnableGravity(bGravity);
	Mymesh->SetSimulatePhysics(bHolding ? false : true);
	Mymesh->SetCollisionEnabled(bHolding ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);

	if (HoldingComp && bHolding) {
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, TEXT("should be picked"));
		Mymesh->AttachToComponent(HoldingComp, FAttachmentTransformRules::KeepWorldTransform);
		SetActorLocation(HoldingComp->GetComponentLocation());
	}

	if (!bHolding) {
		Mymesh->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
		Mymesh->SetWorldLocation(intialPos);
	}
}