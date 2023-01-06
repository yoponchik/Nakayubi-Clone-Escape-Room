// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NumberCountWidget.generated.h"

/**
 * 
 */
UCLASS()
class NAKAYUBI_COPY_API UNumberCountWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Settings", meta = (BindWidget));
	class UTextBlock* UINumberCount;

	void PrintNumberCount();

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

};
