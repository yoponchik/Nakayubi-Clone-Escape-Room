// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle2.generated.h"

//UENUM(BlueprintType)
//enum class EPuzzle2State : uint8 {
//	Unchanged,
//	Changed
//};

UCLASS()
class NAKAYUBI_COPY_API APuzzle2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzle2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

#pragma region Puzzle Interaction
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = PlayerSettings)
	class UStaticMeshComponent* meshComp;

	void MovePosition();
	void MoveToOriginalPosition();

	FVector offsetPosition = FVector(0,0,50);

	UPROPERTY(EditAnywhere, Category = Puzzle)
	bool isPuzzleActorState;

	bool isClicked;

	//deprecated
	//EPuzzle2State puzzle2State;
#pragma  endregion

private:
	FVector originalPosition;
};
