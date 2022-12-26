// Fill out your copyright notice in the Description page of Project Settings.
#include "Clicker.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AClicker::AClicker()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	playerCon = Cast<APlayerController>(GetController());
	if (playerCon != nullptr) {
		playerCon->bShowMouseCursor = true;
	}
}

// Called when the game starts or when spawned
void AClicker::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AClicker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AClicker::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
// 	
// 	FHitResult hitResult;
// 
// 	const ETraceTypeQuery traceChannel = UEngineTypes::ConvertToTraceType(ECC_Visibility);
// 
// 	if (playerCon->GetHitResultUnderCursorByChannel(traceChannel, true, hitResult)){
// 		UKismetSystemLibrary::PrintString(this, hitResult.Location.ToString());
// 	}
}



