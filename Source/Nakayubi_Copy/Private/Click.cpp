// Fill out your copyright notice in the Description page of Project Settings.


#include "Click.h"

#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AClick::AClick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AClick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult hitResult;

	const ETraceTypeQuery traceChannel = UEngineTypes::ConvertToTraceType(ECC_Visibility);

	if (playerCon->GetHitResultUnderCursorByChannel(traceChannel, true, hitResult)) {
		UKismetSystemLibrary::PrintString(this, hitResult.Location.ToString());
	}

}

