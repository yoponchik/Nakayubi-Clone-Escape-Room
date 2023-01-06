// Fill out your copyright notice in the Description page of Project Settings.


#include "NumberCountWidget.h"
#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"



void UNumberCountWidget::PrintNumberCount()
{
	//AMyGameModeBase* gm = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(this));

	//if (gm == nullptr) {
	//	UE_LOG(LogTemp, Warning, TEXT("UNumberCountWidget:Gm 404"));
	//}

	//if (gm != nullptr) {
	//	FText textNumberCount = FText::AsNumber(gm->GetCurrentNumCount());

	//	//change uIcurrrentScore's text
	//	UINumberCount->SetText(textNumberCount);

	//	UE_LOG(LogTemp, Warning, TEXT("PrintNumberCount"));
	//}
}

void UNumberCountWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	//AMyGameModeBase* myGM = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(this));

	//if (myGM != nullptr) {
	//	FText textNumberCount = FText::AsNumber(myGM->GetCurrentNumCount());

	//	//change uIcurrrentScore's text
	//	UINumberCount->SetText(textNumberCount);
	//}

}


