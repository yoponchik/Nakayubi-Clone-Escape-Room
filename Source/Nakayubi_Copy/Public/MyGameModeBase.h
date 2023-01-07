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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=NumData)
	int32 currentNumCount = 0;

	UFUNCTION(BlueprintPure)
	FORCEINLINE int32 GetCurrentNumCount() { return currentNumCount; }

	class UNumberCountWidget* uINumCount;
	
	UPROPERTY(EditAnywhere, Category = DefaultSettings)
	TSubclassOf<class UNumberCountWidget> numCountWidget;

	void AddNumCount(int32 count);



	virtual void BeginPlay() override;


	

};
