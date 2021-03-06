// Copyright Epic Games, Inc. All Rights Reserved.

#include "ForTestTPCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "InteractableEntity.h"
#include "PickupEntity.h"
#include "DrawDebugHelpers.h"

//////////////////////////////////////////////////////////////////////////
// AForTestTPCharacter

AForTestTPCharacter::AForTestTPCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	isTouching = false;

	Location = CreateDefaultSubobject<USceneComponent>(TEXT("Location"));
	Location->SetupAttachment(CameraBoom);
	Location->SetRelativeLocation(FVector(0.000004, 53.999992, 10.000000));
	Location->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));

	HoldingComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HoldingComponent"));
	//HoldingComponent->RelativeLocation.X = 50.0f;
	HoldingComponent->SetupAttachment(Location);
	

	CurrentItem = NULL;
	bCanMove = true;
}

//////////////////////////////////////////////////////////////////////////
// Input

void AForTestTPCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AForTestTPCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AForTestTPCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AForTestTPCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AForTestTPCharacter::LookUpAtRate);

	// handle touch devices
	//PlayerInputComponent->BindTouch(IE_Pressed, this, &AForTestTPCharacter::TouchStarted);
	//PlayerInputComponent->BindTouch(IE_Released, this, &AForTestTPCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AForTestTPCharacter::OnResetVR);
	
	//action for pickup
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &AForTestTPCharacter::OnAction);
	PlayerInputComponent->BindAction("ChangeLevel", IE_Pressed, this, &AForTestTPCharacter::ChangeLevel);
}


void AForTestTPCharacter::OnResetVR()
{
	// If ForTestTP is added to a project via 'Add Feature' in the Unreal Editor the dependency on HeadMountedDisplay in ForTestTP.Build.cs is not automatically propagated
	// and a linker error will result.
	// You will need to either:
	//		Add "HeadMountedDisplay" to [YourProject].Build.cs PublicDependencyModuleNames in order to build successfully (appropriate if supporting VR).
	// or:
	//		Comment or delete the call to ResetOrientationAndPosition below (appropriate if not supporting VR)
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}
/**
void AForTestTPCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AForTestTPCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}
**/

void AForTestTPCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AForTestTPCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AForTestTPCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f) && bCanMove)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AForTestTPCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) && bCanMove)
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AForTestTPCharacter::Tick(float DeltaSeconds) {
	//Tracecheck();
	Start = CameraBoom->GetComponentLocation();
	ForwardVector = CameraBoom->GetForwardVector();
	End = ((ForwardVector * 200.0f) + Start);

	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, -1, 0, 1);

	if (!bHoldingItem) {
		if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility,
			QueryParams, DefaultResponseParam)) {
			//FString HIt_name = Hit.GetActor()->GetClass()->GetDefaultObjectName().ToString();
			//GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, HIt_name);

			if (Hit.GetActor()->ActorHasTag("bInteract")) {
				isTouching = true;
				ItemPos = Hit.GetActor()->GetActorLocation();
			}

			if (Hit.GetActor()->GetClass()->IsChildOf(APickupEntity::StaticClass())) {
				CurrentItem = Cast<APickupEntity>(Hit.GetActor());
			}
		}
		else { 
			CurrentItem = NULL;
			isTouching = false;
		}
	}
}

void AForTestTPCharacter::Tracecheck() {
	Start = CameraBoom->GetComponentLocation();
	ForwardVector = CameraBoom->GetForwardVector();
	End = ((ForwardVector * 200.0f) + Start);

	DrawDebugLine(GetWorld(), Start, End, FColor::Blue, false, -1, 0, 1);

	QueryParams = FCollisionQueryParams("", false, GetOwner());
	bool bIsHIt = GetWorld()->LineTraceSingleByChannel(Hit, Start, End,
		ECollisionChannel::ECC_Visibility, QueryParams, FCollisionResponseParams::DefaultResponseParam);
	if (bIsHIt ) {
		if (bool bHasTag = Hit.GetActor()->ActorHasTag("bInteract")) {
			GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Yellow, TEXT("Press E: Interact"));
			if (!isTouching) {
				//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Press E: Interact"));
				isTouching = true;
			}
			item = Cast<AInteractableEntity>(Hit.GetActor());
			if (item != nullptr) {
				
			}
		}
		else { GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Yellow, TEXT("This Entity cant interact")); }

	}
	else { 
		isTouching = false;
	}
}

void AForTestTPCharacter::OnAction() {
	if (CurrentItem) {
		ToggleItemPickup();
	}
}
// toggle player movement
void AForTestTPCharacter::ChangeLevel(){
	if (LevelNumber == 0) {
		UGameplayStatics::OpenLevel(this, FName("Main"), true);
		LevelNumber = 1;
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Yellow, TEXT("Load Main"));
	}
}

// toggle holding item pickup
void AForTestTPCharacter::ToggleItemPickup() {
	GEngine->AddOnScreenDebugMessage(1, 2, FColor::Yellow, TEXT("Pick"));
	if (CurrentItem) {
		bHoldingItem = !bHoldingItem;
		CurrentItem->Pickup();

		if (!bHoldingItem) {
			CurrentItem = NULL;
		}
	}
}

FVector AForTestTPCharacter::GetItemPos() { return ItemPos; }
bool AForTestTPCharacter::IsTouching() { return isTouching; }
