// Fill out your copyright notice in the Description page of Project Settings.


#include "Puzzle.h"

// Sets default values
APuzzle::APuzzle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//set default values of arrays
	//intialize puzzleSolved = false;
	for (int32 i = 0; i < puzzlePart.Num(); i++) {
		puzzlePart[i] = false;

		puzzleStatus[i] = false;
	}

	puzzleSolved = false;

}

// Called when the game starts or when spawned
void APuzzle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



	//if(clicked), then true
	//if unclicked, then false

	//if hint1 && hint2 && hint3 ,etc
		//puzzleSolved = true

	puzzleSolved = CheckPuzzleStatus();
}

bool APuzzle::CheckPuzzleStatus(){
	for (int32 i = 0; i < puzzlePart.Num(); i++) {
		if (puzzlePart[i] == puzzleSolution[i]) {
			puzzleStatus[i] = true;
			return false;
		}
	}

	return true;
}