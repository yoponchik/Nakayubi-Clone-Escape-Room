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

	UPROPERTY(EditAnywhere, Category = Puzzle)
	TArray <bool> puzzle1Solution;

	UPROPERTY(VisibleAnywhere, Category = Puzzle)
	TArray <bool> isPuzzle1Check;

	UPROPERTY(VisibleAnywhere, Category = Puzzle)
	bool isPuzzle1Solved;

	void AddPuzzle1();
	void UpdatePuzzle1State();
	void CheckPuzzle1State();
#pragma endregion

#pragma region Puzzle 2
	TArray <class APuzzle2*> allPuzzle2Actors;

	UPROPERTY(EditAnywhere, Category = Puzzle)
	TArray <bool> puzzle2Solution;

	UPROPERTY(VisibleAnywhere, Category = Puzzle)
		TArray <bool> isPuzzle2Check;

	UPROPERTY(VisibleAnywhere, Category = Puzzle)
		bool isPuzzle2Solved;

	void AddPuzzle2();
	void UpdatePuzzle2State();
	void CheckPuzzle2State();
#pragma endregion

#pragma region Doors
	UPROPERTY(EditAnywhere, Category = Puzzle)
	TArray <class ADoor*> allDoorActors;

	void AddDoor();
	void ConfirmPuzzle();
#pragma endregion

	//Deprecated
	//UPROPERTY(EditAnywhere, Category = Puzzle)
	//TArray <class AActor*> allActors;
};
