// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Puzzle1.h"
#include "Puzzle2.h"
#include "NumberPuzzle.h"
#include "MyGameModeBase.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

#pragma region Map Enhanced Input
	playerCon = Cast<APlayerController>(GetController());
	if (playerCon != nullptr) {

		UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerCon->GetLocalPlayer());

		if (subsystem != nullptr) {
			subsystem->AddMappingContext(iMCMyMapping, 0);
		}
	}
#pragma endregion

	playerCon->bShowMouseCursor = true;						
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	#pragma region Move Player
	direction.Normalize();
	FVector dir = GetActorLocation() + direction * moveSpeed * DeltaTime;
	SetActorLocation(dir, true);
	#pragma endregion
}

#pragma region Enhanced Input
// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);

	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	enhancedInputComponent->BindAction(iAMovement, ETriggerEvent::Triggered, this, &AMyCharacter::Move);

	enhancedInputComponent->BindAction(iAClick, ETriggerEvent::Triggered, this, &AMyCharacter::Click);
}
#pragma endregion

#pragma region Player Movement
void AMyCharacter::Move(const FInputActionValue& value)
{
	const FVector2D movementVector = value.Get<FVector2D>();

	const FRotator rotation = Controller->GetControlRotation();
	const FRotator yawRotation(0.f, rotation.Yaw, 0.f);

	const FVector forwardDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(forwardDirection, movementVector.Y);
	const FVector rightDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(rightDirection, movementVector.X);

	//UE_LOG(LogTemp, Warning, TEXT("Move"));					//Debug
}

void AMyCharacter::Turn(float value) {
	me->AddControllerYawInput(value);
}

void AMyCharacter::LookUp(float value) {
	me->AddControllerPitchInput(value);
}
#pragma endregion

#pragma region Click
void AMyCharacter::Click() {
	isPlayerClicked = true;
	#pragma region Debug
	//UE_LOG(LogTemp, Warning, TEXT("Click"));
	#pragma endregion

	FHitResult hitResult;
	const ETraceTypeQuery TraceChannel = UEngineTypes::ConvertToTraceType((ECC_Visibility));

	//If Hit result has the channel trace channel, if it is hit result...
	if (playerCon->GetHitResultUnderCursorByChannel(TraceChannel, true, hitResult)) {

		if (!isPlayerClicked) { return; }
		clickedActor = hitResult.GetActor();									//if Clicked, get the actor
	#pragma region Debug
		//Get Actor Name
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *clickedActor->GetName());						//Need asterisk because need pointer to print out character
	#pragma endregion

		CheckPuzzleType();
	}
}
#pragma endregion

#pragma region Check Puzzle Type
void AMyCharacter::CheckPuzzleType()
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
#pragma endregion
