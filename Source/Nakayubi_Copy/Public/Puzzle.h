// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle.generated.h"

UCLASS()
class NAKAYUBI_COPY_API APuzzle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//bool arrays
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PuzzleSettings)
	TArray<bool> puzzleSolution;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PuzzleSettings)
	TArray<bool> puzzlePart;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PuzzleStatus)
	TArray<bool> puzzleStatus;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PuzzleStatus)
	bool puzzleSolved;

	bool CheckPuzzleStatus();
};
