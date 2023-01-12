// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MyCharacter.generated.h"

UCLASS()
class NAKAYUBI_COPY_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Player Settings | Movement")
	float moveSpeed = 800;
private:
	#pragma region Enhanced Input
	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)
	class UInputAction* iAMovement;

	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)
	class UInputAction* iAClick;

	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)
	class UInputMappingContext* iMCMyMapping;
#pragma endregion

	#pragma region Movement
	UFUNCTION()
	void Move(const FInputActionValue& value);

	void Turn(float value);
	void LookUp(float value);
	#pragma endregion

	UFUNCTION()
	void Click();

	void CheckPuzzleType();								//Checks which class the puzzle is when clicked

	AMyCharacter* me;									//For turning the camera

	APlayerController* playerCon;						//For mapping the enhanced input

	class AActor* clickedActor;

	FVector direction;
};
