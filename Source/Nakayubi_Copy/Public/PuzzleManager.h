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

	UPROPERTY(EditAnywhere, Category = Puzzle)
	TArray <bool> puzzle1Solution;
	TArray <class APuzzle1*> allPuzzle1Actors;

	UPROPERTY(EditAnywhere, Category = Puzzle)
	TArray <bool> puzzle2Solution;
	TArray <class APuzzle2*> allPuzzle2Actors;

	UPROPERTY(EditAnywhere, Category = Puzzle)
	TArray <class ADoor*> allDoorActors;

	void AddPuzzle1();
	void UpdatePuzzle1State();
	void CheckPuzzle1State();

	void AddPuzzle2();
	void UpdatePuzzle2State();
	void CheckPuzzle2State();

	void AddDoor();
	void ConfirmPuzzle();

	UPROPERTY(VisibleAnywhere, Category = Puzzle)
	TArray <bool> isPuzzle1Check;
	UPROPERTY(VisibleAnywhere, Category = Puzzle)
	bool isPuzzle1Solved;

	UPROPERTY(VisibleAnywhere, Category = Puzzle)
	TArray <bool> isPuzzle2Check;
	UPROPERTY(VisibleAnywhere, Category = Puzzle)
	bool isPuzzle2Solved;



	//Deprecated
	//UPROPERTY(EditAnywhere, Category = Puzzle)
	//TArray <class AActor*> allActors;


};
