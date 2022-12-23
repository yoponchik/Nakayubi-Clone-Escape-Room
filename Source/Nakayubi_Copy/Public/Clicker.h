// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Clicker.generated.h"

UCLASS()
class NAKAYUBI_COPY_API AClicker : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AClicker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnMouseClick();

	void OnFingerTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	
};
