// Fill out your copyright notice in the Description page of Project Settings.


#include "NumberCountWidget.h"
#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"

//This script has a lot of errors
//=======================================================
//=======================================================
//=======================================================

void UNumberCountWidget::PrintNumberCount()
{
	//AMyGameModeBase* gm = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(this));

	//this doesn't work for some reason??
	//cause of crash
	gm = Cast<AMyGameModeBase>(GetWorld()->GetAuthGameMode());

	if (gm == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("UNumberCountWidget:gm not found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("gm found"));
		
		FText textCount = FText::AsNumber(gm->GetCurrentNumCount());
		
		//change uIcurrrentScore's text
		textNumberCount->SetText(textCount);

		UE_LOG(LogTemp, Warning, TEXT("textCount"));
	}
}

//void UNumberCountWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
//{
	//Super::NativeTick(MyGeometry, InDeltaTime);

	//AMyGameModeBase* myGM = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(this));

	//if (myGM != nullptr) {
	//	FText textNumberCount = FText::AsNumber(myGM->GetCurrentNumCount());

	//	//change uIcurrrentScore's text
	//	UINumberCount->SetText(textNumberCount);
	//}

//}


