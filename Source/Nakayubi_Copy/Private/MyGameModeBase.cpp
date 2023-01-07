// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "NumberCountWidget.h"

void AMyGameModeBase::BeginPlay()
{
	//if (uINumCount != nullptr)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AMyGameModeBase:uINumCount found"));
	//	uINumCount = CreateWidget<UNumberCountWidget>(GetWorld(), numCountWidget);
		//
	//	if (uINumCount != nullptr) {  
	//		uINumCount->AddToViewport();											//draw score ui in viewport

	//		uINumCount->PrintNumberCount();											//draw score ui in viewport
	//	}									//nullptr checker for main UI
	//}
}

void AMyGameModeBase::AddNumCount(int32 count)
{
	count = currentNumCount;

	uINumCount->PrintNumberCount();

}
