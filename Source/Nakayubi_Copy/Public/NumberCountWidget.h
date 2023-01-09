// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NumberCountWidget.generated.h"

/**
 * 
 */

 //This script has a lot of errors
//=======================================================
//=======================================================
//=======================================================

UCLASS()
class NAKAYUBI_COPY_API UNumberCountWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Settings", meta = (BindWidget));
	class UTextBlock* textNumberCount;

	void PrintNumberCount();

};
