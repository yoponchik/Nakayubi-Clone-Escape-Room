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

	void AddPuzzle();

	void UpdatePuzzle1State();

	void CheckPuzzle1State();

	UPROPERTY(VisibleAnywhere, Category = Puzzle)
	TArray <bool> isPuzzle1Check;

	UPROPERTY(VisibleAnywhere, Category = Puzzle)
	bool isPuzzle1Solved;

	//Deprecated
	//UPROPERTY(EditAnywhere, Category = Puzzle)
	//TArray <class AActor*> allActors;


};
