// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ForTestTPCharacter.generated.h"

UCLASS(config=Game)
class AForTestTPCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AForTestTPCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	//void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	//oid TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UPROPERTY(EditAnywhere)
		class USceneComponent* Location;

	UPROPERTY(EditAnywhere)
		class USceneComponent* HoldingComponent;

	FVector Start;
	FVector ForwardVector;
	FVector End;
	bool isTouching;

	FHitResult Hit;
	FCollisionQueryParams QueryParams;
	FCollisionResponseParams DefaultResponseParam;

	class AInteractableEntity* item;

	void Tick(float DeltaSeconds);
	void Tracecheck();

	UPROPERTY(EditAnywhere)
		class APickupEntity* CurrentItem;
	bool bHoldingItem;
	bool bCanMove;

public:

	int LevelNumber;
	UFUNCTION(BlueprintCallable)
	void OnAction();

	UFUNCTION(BlueprintCallable)
		void ChangeLevel();
	UFUNCTION(BlueprintCallable)
	FVector GetItemPos();
	UFUNCTION(BlueprintCallable)
	bool IsTouching();

	// toggle holding item pickup
	void ToggleItemPickup();

private:
	FVector ItemPos;

};


