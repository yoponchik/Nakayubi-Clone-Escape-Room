// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleManager.h"
#include "Puzzle1.h"

// Sets default values
APuzzleManager::APuzzleManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	isPuzzle1Solved = false;

}

// Called when the game starts or when spawned
void APuzzleManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckPuzzle1State();
}

void APuzzleManager::CheckPuzzle1State()
{
	for(int32 i = 0; i < allActors.Num(); i++){
		if(allActors[i]->IsA(APuzzle1::StaticClass())){										//Check if the actor is a APuzzle1 class type

			allPuzzle1Actors[i] = Cast<APuzzle1>(allActors[i]);					//Cast AActor to APuzzle1

			if(allPuzzle1Actors[i] != nullptr){
				if ((allPuzzle1Actors[i]->isPuzzleActorState) == puzzle1Solution[i]) {			//Check if puzzle state = puzzle solution
					isPuzzle1Solved = true;														//flag puzzle as solved
					UE_LOG(LogTemp, Warning, TEXT("Puzzle 1 Solved"));
				}
			}

		}
	}
}

