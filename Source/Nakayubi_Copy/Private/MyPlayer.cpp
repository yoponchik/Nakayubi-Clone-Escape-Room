// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Puzzle1.h"
#include "Puzzle2.h"


// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	playerController = UGameplayStatics::GetPlayerController(this, 0);
	playerController->bShowMouseCursor = true;

	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult hitResult;
	const ETraceTypeQuery TraceChannel = UEngineTypes::ConvertToTraceType((ECC_Visibility));

	//If Hit result has the channel trace channel, if it is hit result...
	if (playerController->GetHitResultUnderCursorByChannel(TraceChannel, true, hitResult)) {

		if (!isPlayerClicked) {return; }
		clickedActor = hitResult.GetActor();									//if Clicked, get the actor
#pragma region Debug
		//Get Actor Name
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *clickedActor->GetName());						//Need asterisk because need pointer to print out character
#pragma endregion

		CheckPuzzleType();
	}
}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Click", IE_Pressed, this, &AMyPlayer::Click);
	PlayerInputComponent->BindAction("Click", IE_Released, this, &AMyPlayer::UnClick);
}

void AMyPlayer::Click() {
	isPlayerClicked = true;
#pragma region Debug
	//UE_LOG(LogTemp, Warning, TEXT("Click"));
#pragma endregion
}

void AMyPlayer::UnClick() {
	isPlayerClicked = false;
#pragma region Debug
	//UE_LOG(LogTemp, Warning, TEXT("Click End"));
#pragma endregion
}

void AMyPlayer::CheckPuzzleType()
{
	if (clickedActor->IsA<APuzzle1>()) {									//if clickedActor is puzzle1
	//if (Cast<APuzzle1>(clickedActor)) {									//Either works
#pragma region Debug
			//Extracted Actor is APuzzle1 class
		//UE_LOG(LogTemp, Warning, TEXT("iS A PUZZLE1"));						//Need asterisk because need pointer to print out character
#pragma endregion

		APuzzle1* puzzle1 = Cast<APuzzle1>(clickedActor); 									//Either works
		//puzzle1->puzzle1State = EPuzzle1State::Changed;
		puzzle1->isClicked = !(puzzle1->isClicked);
	}

	if (clickedActor->IsA<APuzzle2>()) {									//if clickedActor is puzzle1

		APuzzle2* puzzle2 = Cast<APuzzle2>(clickedActor); 									//Either works
		//puzzle2->puzzle2State = EPuzzle2State::Changed;
		puzzle2->isClicked = !(puzzle2->isClicked);
	}
}
