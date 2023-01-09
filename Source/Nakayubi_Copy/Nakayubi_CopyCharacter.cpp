// Copyright Epic Games, Inc. All Rights Reserved.

#include "Nakayubi_CopyCharacter.h"
#include "Nakayubi_CopyProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "Kismet/GameplayStatics.h"
#include "Puzzle1.h"
#include "Puzzle2.h"
#include "NumberPuzzle.h"
#include "MyGameModeBase.h"


//////////////////////////////////////////////////////////////////////////
// ANakayubi_CopyCharacter

ANakayubi_CopyCharacter::ANakayubi_CopyCharacter()
{
	// Character doesnt have a rifle at start
	bHasRifle = false;
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

}

void ANakayubi_CopyCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}


	playerController = UGameplayStatics::GetPlayerController(this, 0);
	playerController->bShowMouseCursor = true;

	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);


}

void ANakayubi_CopyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult hitResult;
	const ETraceTypeQuery TraceChannel = UEngineTypes::ConvertToTraceType((ECC_Visibility));

	//If Hit result has the channel trace channel, if it is hit result...
	if (playerController->GetHitResultUnderCursorByChannel(TraceChannel, true, hitResult)) {

		if (!isPlayerClicked) { return; }
		clickedActor = hitResult.GetActor();									//if Clicked, get the actor
#pragma region Debug
		//Get Actor Name
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *clickedActor->GetName());						//Need asterisk because need pointer to print out character
#pragma endregion

		CheckPuzzleType();
	}
}

//////////////////////////////////////////////////////////////////////////// Input

void ANakayubi_CopyCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ANakayubi_CopyCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ANakayubi_CopyCharacter::Look);
	}

	PlayerInputComponent->BindAction("Click", IE_Pressed, this, &ANakayubi_CopyCharacter::Click);
	PlayerInputComponent->BindAction("Click", IE_Released, this, &ANakayubi_CopyCharacter::UnClick);
}

void ANakayubi_CopyCharacter::Click() {
	isPlayerClicked = true;
#pragma region Debug
	//UE_LOG(LogTemp, Warning, TEXT("Click"));
#pragma endregion
}

void ANakayubi_CopyCharacter::UnClick() {
	isPlayerClicked = false;
#pragma region Debug
	//UE_LOG(LogTemp, Warning, TEXT("Click End"));
#pragma endregion
}

void ANakayubi_CopyCharacter::CheckPuzzleType()
{
	if (clickedActor->IsA<APuzzle1>()) {									//if clickedActor is puzzle1
	//if (Cast<APuzzle1>(clickedActor)) {									//Either works

#pragma region Debug
			//Extracted Actor is APuzzle1 class
		//UE_LOG(LogTemp, Warning, TEXT("iS A PUZZLE1"));						//Need asterisk because need pointer to print out character
#pragma endregion
		APuzzle1* puzzle1 = Cast<APuzzle1>(clickedActor);
		puzzle1->isClicked = !(puzzle1->isClicked);
		//puzzle1->puzzle1State = EPuzzle1State::Changed;					//deprecated
	}

	if (clickedActor->IsA<APuzzle2>()) {									//if clickedActor is puzzle1

#pragma region Debug
			//Extracted Actor is APuzzle1 class
		//UE_LOG(LogTemp, Warning, TEXT("iS A PUZZLE2"));						//Need asterisk because need pointer to print out character
#pragma endregion
		APuzzle2* puzzle2 = Cast<APuzzle2>(clickedActor);
		puzzle2->isClicked = !(puzzle2->isClicked);
		//puzzle2->puzzle2State = EPuzzle2State::Changed;					//deprecated
	}

	if (clickedActor->IsA<ANumberPuzzle>()) {									//if clickedActor is puzzle1
#pragma region Debug
		//UE_LOG(LogTemp, Warning, TEXT("iS A NumberPuzzle"));						//Need asterisk because need pointer to print out character
#pragma endregion

		ANumberPuzzle* numpuzzle = Cast<ANumberPuzzle>(clickedActor);


		//to tell the numpuzzle that it is clicked
		numpuzzle->isClicked = !(numpuzzle->isClicked);

		//temporary
		//Count up every click
		(numpuzzle->roundCount++);
		(numpuzzle->roundCount) /= (11.0f);

		if ((numpuzzle->roundCount) >= 0.1f) {
			numpuzzle->count++;
			(numpuzzle->roundCount) = 0;
		}

		//UE_LOG(LogTemp, Warning, TEXT("Count: %f"), numpuzzle->roundCount);						
		UE_LOG(LogTemp, Warning, TEXT("Count: %d"), numpuzzle->count);

	}
}

void ANakayubi_CopyCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ANakayubi_CopyCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ANakayubi_CopyCharacter::SetHasRifle(bool bNewHasRifle)
{
	bHasRifle = bNewHasRifle;
}

bool ANakayubi_CopyCharacter::GetHasRifle()
{
	return bHasRifle;
}