// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NumberPuzzle.generated.h"

UCLASS()
class NAKAYUBI_COPY_API ANumberPuzzle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANumberPuzzle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = NumberPuzzle)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(VisibleAnywhere, Category = NumberPuzzle)
	bool isClicked;

	int32 count;

	float roundCount;


	class AMyGameModeBase* gm;
};
