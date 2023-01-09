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

	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)
		class UInputAction* iAHorizontal;

	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)
		class UInputAction* iAVertical;

	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)
		class UInputAction* iAMovement;


	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)
		class UInputAction* iAClick;


	UPROPERTY(EditDefaultsOnly, Category = PlayerSettings)
		class UInputMappingContext* iMCMyMapping;



	float hori;

	float verti;

	UFUNCTION(BlueprintCallable)
		void Move(const FInputActionValue& value);

	UFUNCTION(BlueprintCallable)
		void Horizontal(const FInputActionValue& value);
	UFUNCTION(BlueprintCallable)
		void Vertical(const FInputActionValue& value);

	float moveSpeed = 800;
	FVector direction;

	void Turn(float value);
	void LookUp(float value);

	UPROPERTY()
	AMyCharacter* me;

	bool isPlayerClicked;

	class AMyGameModeBase* gm;


	class AActor* clickedActor;

	UFUNCTION(BlueprintCallable)
	void Click();
	void UnClick();

	void CheckPuzzleType();

	APlayerController* playerCon;

};
