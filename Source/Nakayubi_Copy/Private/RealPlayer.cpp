// Fill out your copyright notice in the Description page of Project Settings.


#include "RealPlayer.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "MyPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Puzzle1.h"
#include "Puzzle2.h"
#include "NumberPuzzle.h"
#include "MyGameModeBase.h"

// Sets default values
ARealPlayer::ARealPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARealPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	playerCon = Cast<APlayerController>(GetController());
	if (playerCon != nullptr) {
		UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerCon->GetLocalPlayer());


		if (subsystem != nullptr) {
			subsystem->AddMappingContext(iMCMyMapping, 0);
		}
	}

	playerCon->bShowMouseCursor = true;
	//playerCon->bEnableClickEvents = true;
	//playerCon->bEnableMouseOverEvents = true;

}

// Called every frame
void ARealPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	direction.Normalize();
	FVector dir = GetActorLocation() + direction * moveSpeed * DeltaTime;
	SetActorLocation(dir, true);

//	FHitResult hitResult;
//	const ETraceTypeQuery TraceChannel = UEngineTypes::ConvertToTraceType((ECC_Visibility));
//
//	//If Hit result has the channel trace channel, if it is hit result...
//	if (playerCon->GetHitResultUnderCursorByChannel(TraceChannel, true, hitResult)) {
//
//		if (!isPlayerClicked) { return; }
//		clickedActor = hitResult.GetActor();									//if Clicked, get the actor
//#pragma region Debug
//		//Get Actor Name
//		//UE_LOG(LogTemp, Warning, TEXT("%s"), *clickedActor->GetName());						//Need asterisk because need pointer to print out character
//#pragma endregion
//
//		CheckPuzzleType();
//	}
}

// Called to bind functionality to input
void ARealPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	//enhancedInputComponent->BindAction(iAHorizontal, ETriggerEvent::Triggered, this, &ARealPlayer::Horizontal);
	//enhancedInputComponent->BindAction(iAHorizontal, ETriggerEvent::Completed, this, &ARealPlayer::Horizontal);
	//
	//enhancedInputComponent->BindAction(iAVertical, ETriggerEvent::Triggered, this, &ARealPlayer::Vertical);
	//enhancedInputComponent->BindAction(iAVertical, ETriggerEvent::Completed, this, &ARealPlayer::Vertical);

	PlayerInputComponent->BindAxis("Turn", this, &ARealPlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ARealPlayer::AddControllerPitchInput);

	//PlayerInputComponent->BindAction("Click", IE_Pressed, this, &ARealPlayer::Click);
	//PlayerInputComponent->BindAction("Click", IE_Released, this, &ARealPlayer::UnClick);
	
	enhancedInputComponent->BindAction(iAMovement, ETriggerEvent::Triggered, this, &ARealPlayer::Move);

	enhancedInputComponent->BindAction(iAClick, ETriggerEvent::Triggered, this, &ARealPlayer::Click);
	//enhancedInputComponent->BindAction(iAClick, ETriggerEvent::Completed, this, &ARealPlayer::Click);
}

void ARealPlayer::Move(const FInputActionValue& value)
{
	const FVector2D movementVector = value.Get<FVector2D>();

	const FRotator rotation = Controller->GetControlRotation();
	const FRotator yawRotation(0.f, rotation.Yaw, 0.f);

	const FVector forwardDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(forwardDirection, movementVector.Y);
	const FVector rightDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(rightDirection, movementVector.X);

	UE_LOG(LogTemp, Warning, TEXT("Move"));

}

void ARealPlayer::Horizontal(const FInputActionValue& value)
{
	hori = value.Get<float>();
	UE_LOG(LogTemp, Warning, TEXT("h: %.4f"), hori);
	
	direction.Y = hori;
}

void ARealPlayer::Vertical(const FInputActionValue& value)
{
	verti = value.Get<float>();
	UE_LOG(LogTemp, Warning, TEXT("h: %.4f"), verti);
	direction.X = verti;
}

void ARealPlayer::Turn(float value){
	me->AddControllerYawInput(value);
}

void ARealPlayer::LookUp(float value){
	me->AddControllerPitchInput(value);
}

void ARealPlayer::Click() {
	isPlayerClicked = true;
#pragma region Debug
	UE_LOG(LogTemp, Warning, TEXT("Click"));
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

void ARealPlayer::UnClick() {
	isPlayerClicked = false;
#pragma region Debug
	//UE_LOG(LogTemp, Warning, TEXT("Click End"));
#pragma endregion
}

void ARealPlayer::CheckPuzzleType()
{
	if (clickedActor->IsA<APuzzle1>()) {									//if clickedActor is puzzle1
	//if (Cast<APuzzle1>(clickedActor)) {									//Either works

#pragma region Debug
			//Extracted Actor is APuzzle1 class
		UE_LOG(LogTemp, Warning, TEXT("iS A PUZZLE1"));						//Need asterisk because need pointer to print out character
#pragma endregion
		APuzzle1* puzzle1 = Cast<APuzzle1>(clickedActor);
		puzzle1->isClicked = !(puzzle1->isClicked);
		//puzzle1->puzzle1State = EPuzzle1State::Changed;					//deprecated
	}

	if (clickedActor->IsA<APuzzle2>()) {									//if clickedActor is puzzle1

#pragma region Debug
			//Extracted Actor is APuzzle1 class
		UE_LOG(LogTemp, Warning, TEXT("iS A PUZZLE2"));						//Need asterisk because need pointer to print out character
#pragma endregion
		APuzzle2* puzzle2 = Cast<APuzzle2>(clickedActor);
		puzzle2->isClicked = !(puzzle2->isClicked);
		//puzzle2->puzzle2State = EPuzzle2State::Changed;					//deprecated
	}

	if (clickedActor->IsA<ANumberPuzzle>()) {									//if clickedActor is puzzle1
#pragma region Debug
		UE_LOG(LogTemp, Warning, TEXT("iS A NumberPuzzle"));						//Need asterisk because need pointer to print out character
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