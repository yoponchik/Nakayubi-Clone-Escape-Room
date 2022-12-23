// Fill out your copyright notice in the Description page of Project Settings.
#include "Clicker.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AClicker::AClicker()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	
	InputComponent->BindAction("MouseClick", IE_Pressed, this, &AClicker::OnMouseClick);

	//support touch devices 
	//InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AClicker::OnFingerTouch);

}

void AClicker::OnMouseClick()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Pawn, false, HitResult);

	if (HitResult.GetComponent())
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Mouse Click+++ Component: %s"), *HitResult.GetComponent()->GetName()));
	}

	if (HitResult.GetActor())
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Mouse Click+++ Actor: %s"), *HitResult.GetActor()->GetName()));
	}
}

void AClicker::OnFingerTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FHitResult HitResult;
	GetHitResultUnderFinger(ETouchIndex::Type::Touch1, ECollisionChannel::ECC_Pawn, false, HitResult);

	if (HitResult.GetComponent())
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Finger Touch +++ Component: %s"), *HitResult.GetComponent()->GetName()));
	}

	if (HitResult.GetActor())
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Finger Touch +++ Actor: %s"), *HitResult.GetActor()->GetName()));
	}
}


