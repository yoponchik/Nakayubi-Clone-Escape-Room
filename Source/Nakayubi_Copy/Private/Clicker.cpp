// Fill out your copyright notice in the Description page of Project Settings.


#include "Clicker.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AClicker::AClicker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AClicker::BeginPlay()
{
	Super::BeginPlay();
	playerController = UGameplayStatics::GetPlayerController(this, 0);
	playerController->bShowMouseCursor = true;
}

// Called every frame
void AClicker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult HitResult;

	const ETraceTypeQuery TraceChannel = UEngineTypes::ConvertToTraceType((ECC_Visibility));

	if (playerController->GetHitResultUnderCursorByChannel(TraceChannel, true, HitResult)) {
		//Get the actor

		UKismetSystemLibrary::PrintString(this, *HitResult.GetActor()->GetName());

		//Access script of the actor

		//change material
	}
}



