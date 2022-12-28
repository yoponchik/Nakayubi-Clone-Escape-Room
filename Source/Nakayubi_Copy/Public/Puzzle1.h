// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle1.generated.h"

UCLASS()
class NAKAYUBI_COPY_API APuzzle1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzle1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = PlayerSettings)
	class UStaticMeshComponent* meshComp;

	void ChangeMaterialColor();
	void ChangeToOriginalColor();
private:

	FLinearColor initColor;
	UMaterialInstanceDynamic* dynamicMat;

};
