// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupEntity.h"
#include "Tool.generated.h"

/**
 * 
 */
UCLASS()
class FORTESTTP_API ATool : public APickupEntity
{
	GENERATED_BODY()

private:
	FVector intialPos;

protected:
	void BeginPlay() override;

public:

	void Pickup() override;
	
};
