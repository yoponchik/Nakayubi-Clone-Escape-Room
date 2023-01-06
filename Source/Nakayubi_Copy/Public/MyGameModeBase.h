// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class NAKAYUBI_COPY_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = DefaultSettings)
	TSubclassOf<class UNumberCountWidget> numCountWidget;

	UFUNCTION(BlueprintPure)
	FORCEINLINE int32 GetCurrentNumCount() { return currentNumCount; }

	int32 currentNumCount = 0;

	class UNumberCountWidget* uINumCount;

	virtual void BeginPlay() override;

	void AddNumCount(int32 count);

	

};
