// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuzzleManager.generated.h"

UCLASS()
class NAKAYUBI_COPY_API APuzzleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzleManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

#pragma region Puzzle 1
	TArray <class APuzzle1*> allPuzzle1Actors;

	UPROPERTY(EditAnywhere, Category = "Puzzle | Puzzle1")
	TArray <bool> puzzle1Solution;

	UPROPERTY(EditAnywhere, Category = "Puzzle | Puzzle1")
	TArray <bool> isPuzzle1Check;

	UPROPERTY(EditAnywhere, Category = "Puzzle | Puzzle1")
	bool isPuzzle1Solved;
#pragma endregion

#pragma region Puzzle 2
	TArray <class APuzzle2*> allPuzzle2Actors;

	UPROPERTY(EditAnywhere, Category = "Puzzle | Puzzle2")
	TArray <bool> puzzle2Solution;

	UPROPERTY(EditAnywhere, Category = "Puzzle | Puzzle2")
	TArray <bool> isPuzzle2Check;

	UPROPERTY(EditAnywhere, Category = "Puzzle | Puzzle2")
	bool isPuzzle2Solved;
#pragma endregion

#pragma region Doors
	UPROPERTY(EditAnywhere, Category = Puzzle)
	TArray <class ADoor*> allDoorActors;
#pragma endregion

	//Deprecated
	//UPROPERTY(EditAnywhere, Category = Puzzle)
	//TArray <class AActor*> allActors;

private: 
	//Add Actors to Array
	void AddPuzzle1();
	void AddPuzzle2();
	void AddDoor();

	//Constantly check puzzle states; update check array
	void UpdatePuzzle1State();
	void UpdatePuzzle2State();

	//Check array 
	void CheckPuzzle1State();
	void CheckPuzzle2State();

	//Doors
	void ConfirmPuzzle();
};
