// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableEntity.generated.h"

UCLASS()
class FORTESTTP_API AInteractableEntity : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableEntity();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* center;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* shape;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UTextRenderComponent* outputText;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Interact();

	void ShowText();

};
