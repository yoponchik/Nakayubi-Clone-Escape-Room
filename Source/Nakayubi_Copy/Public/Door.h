// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class NAKAYUBI_COPY_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = PlayerSettings)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DoorSettings)
	FVector offsetPosition = FVector(0, 0, 50);										//How much the door will open

	void OpenDoor();
	void CloseDoor();
	
	//Deprecated
	//EPuzzle2State puzzle2State;
private:
	FVector originalPosition;

};
