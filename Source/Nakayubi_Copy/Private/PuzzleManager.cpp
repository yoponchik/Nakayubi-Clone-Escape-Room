// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleManager.h"
#include "Puzzle1.h"
#include "Puzzle2.h"
#include "Door.h"


#include "EngineUtils.h"

// Sets default values
APuzzleManager::APuzzleManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APuzzleManager::BeginPlay()
{
	Super::BeginPlay();

	//Deprecated
	//allPuzzle1Actors.Init(nullptr, allActors.Num());

	isPuzzle1Check.Init(false, puzzle1Solution.Num());
	isPuzzle2Check.Init(false, puzzle2Solution.Num());
	
	for(int32 i = 0; i < isPuzzle1Check.Num(); i++){
		isPuzzle1Check[i] = false;
	}	
	for (int32 i = 0; i < isPuzzle2Check.Num(); i++) {
		isPuzzle2Check[i] = false;
	}

	#pragma region Debug
	for(int32 i = 0; i < isPuzzle1Check.Num(); i++){
		if(isPuzzle1Check[i]){
			UE_LOG(LogTemp, Warning, TEXT("isPuzzle1Check:Index %d = true"), i);
		}
		else{
			UE_LOG(LogTemp, Warning, TEXT("isPuzzle1Check:Index %d = false"), i);
		}
	}
	#pragma endregion

	AddPuzzle1();
	AddPuzzle2();
	AddDoor();
}

// Called every frame
void APuzzleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

#pragma region Deprecated

	//if(!isPuzzle1Solved){
	//	CheckPuzzle1State();
	//}
	//else{
	//	return;
	//}

#pragma endregion

	CheckPuzzle1State();
	UpdatePuzzle1State();

	CheckPuzzle2State();
	UpdatePuzzle2State();

	ConfirmPuzzle();
}

void APuzzleManager::AddPuzzle1()
{	
	for (TActorIterator<APuzzle1> it(GetWorld()); it; ++it) {
		allPuzzle1Actors.Add(*it);
	}
	//UE_LOG(LogTemp,Warning,TEXT("size : %d"),allPuzzle1Actors.Num());
}

void APuzzleManager::UpdatePuzzle1State()
{
	if(allPuzzle1Actors.Num() != puzzle1Solution.Num()){
		UE_LOG(LogTemp, Warning, TEXT("Number of Puzzle Actors and Solutions do not match. Check the details window."));
		return;
	}

	for (int32 i = 0; i < allPuzzle1Actors.Num(); i++) {
		if ((allPuzzle1Actors[i]->isPuzzleActorState) == puzzle1Solution[i]) {
			isPuzzle1Check[i] = true;
		}
		else {
			isPuzzle1Check[i] = false;
		}
	}
	

	//for (int32 i = 0; i < isPuzzle1Check.Num(); i++) {
	//	if (isPuzzle1Check[i]) {
	//		UE_LOG(LogTemp, Warning, TEXT("isPuzzle1Check:Index %d = true"), i);
	//	}
	//	else {
	//		UE_LOG(LogTemp, Warning, TEXT("isPuzzle1Check:Index %d = false"), i);
	//	}
	//}
}

void APuzzleManager::CheckPuzzle1State()
{
	for (int32 i = 0; i < isPuzzle1Check.Num(); i++) {
		if(!isPuzzle1Check[i]){
			isPuzzle1Solved = false;
			break;
		}

		isPuzzle1Solved = true;
	}
}

void APuzzleManager::AddPuzzle2()
{
	for (TActorIterator<APuzzle2> it(GetWorld()); it; ++it) {
		allPuzzle2Actors.Add(*it);
	}
}

void APuzzleManager::UpdatePuzzle2State()
{
	if (allPuzzle2Actors.Num() != puzzle2Solution.Num()) {
		UE_LOG(LogTemp, Warning, TEXT("Number of Puzzle Actors and Solutions do not match. Check the details window."));
		return;
	}

	for (int32 i = 0; i < allPuzzle2Actors.Num(); i++) {
		if ((allPuzzle2Actors[i]->isPuzzleActorState) == puzzle2Solution[i]) {
			isPuzzle2Check[i] = true;
		}
		else {
			isPuzzle2Check[i] = false;
		}
	}
}

void APuzzleManager::CheckPuzzle2State()
{
	for (int32 i = 0; i < isPuzzle2Check.Num(); i++) {
		if (!isPuzzle2Check[i]) {
			isPuzzle2Solved = false;
			break;
		}

		isPuzzle2Solved = true;
	}
}

void APuzzleManager::AddDoor()
{
	for (TActorIterator<ADoor> it(GetWorld()); it; ++it) {
		allDoorActors.Add(*it);
	}
}

void APuzzleManager::ConfirmPuzzle()
{
	if (allDoorActors.Num() != 2) {
		UE_LOG(LogTemp, Warning, TEXT("Number of Door Actors and Solutions do not match. Check the details window."));
		return;
	}
	if(isPuzzle1Solved){
		allDoorActors[0]->OpenDoor();
	}
	else{
		allDoorActors[0]->CloseDoor();
	}	
	if(isPuzzle2Solved){
		allDoorActors[1]->OpenDoor();
	}
	else{
		allDoorActors[1]->CloseDoor();
	}
}

#pragma region Deprecated
	//if(allActors.Num() != allPuzzle1Actors.Num()){
	//	UE_LOG(LogTemp, Warning, TEXT("Number of Puzzle Actors and Solutions do not match. Check the details window."));
	//	return;
	#pragma region Deprecated
		//if(allActors[i]->IsA(APuzzle1::StaticClass())){										//Check if the actor is a APuzzle1 class type

		//	allPuzzle1Actors[i] = Cast<APuzzle1>(allActors[i]);					//Cast AActor to APuzzle1

		//	if(allPuzzle1Actors[i] != nullptr){
		//		if ((allPuzzle1Actors[i]->isPuzzleActorState) == puzzle1Solution[i]) {			//Check if puzzle state = puzzle solution
		//			isPuzzle1Solved = true;														//flag puzzle as solved
		//			
		//			#pragma region Debug
		//			//if(allPuzzle1Actors[i]->isPuzzleActorState){
		//			//	UE_LOG(LogTemp, Warning, TEXT("isPuzzleActorState %d =True"), i);
		//			//}
		//			//else{
		//			//	UE_LOG(LogTemp, Warning, TEXT("isPuzzleActorState %d =False"), i);
		//			//}
		//			#pragma endregion

		//			#pragma region Debug
		//			//if(puzzle1Solution[i]){
		//			//	UE_LOG(LogTemp, Warning, TEXT("puzzle1Solution %d =True"), i);
		//			//}
		//			//else{
		//			//	UE_LOG(LogTemp, Warning, TEXT("puzzle1Solution %d =False"), i);
		//			//}
		//			#pragma endregion
		//		}
		//	}
		//}
	#pragma endregion
#pragma endregion

