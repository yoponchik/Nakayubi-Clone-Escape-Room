// Fill out your copyright notice in the Description page of Project Settings.


#include "RealPlayer.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


// Sets default values
ARealPlayer::ARealPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARealPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* playerCon = Cast<APlayerController>(GetController());
	if (playerCon != nullptr) {
		UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerCon->GetLocalPlayer());


		if (subsystem != nullptr) {
			subsystem->AddMappingContext(iMCMyMapping, 0);
		}
	}

	playerCon->bShowMouseCursor = true;
	//playerCon->bEnableClickEvents = true;
	//playerCon->bEnableMouseOverEvents = true;

}

// Called every frame
void ARealPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	direction.Normalize();
	FVector dir = GetActorLocation() + direction * moveSpeed * DeltaTime;
	SetActorLocation(dir, true);
}

// Called to bind functionality to input
void ARealPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	enhancedInputComponent->BindAction(iAHorizontal, ETriggerEvent::Triggered, this, &ARealPlayer::Horizontal);
	enhancedInputComponent->BindAction(iAHorizontal, ETriggerEvent::Completed, this, &ARealPlayer::Horizontal);
	
	enhancedInputComponent->BindAction(iAVertical, ETriggerEvent::Triggered, this, &ARealPlayer::Vertical);
	enhancedInputComponent->BindAction(iAVertical, ETriggerEvent::Completed, this, &ARealPlayer::Vertical);

	PlayerInputComponent->BindAxis("Turn", this, &ARealPlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ARealPlayer::AddControllerPitchInput);
}

void ARealPlayer::Horizontal(const FInputActionValue& value)
{
	hori = value.Get<float>();
	UE_LOG(LogTemp, Warning, TEXT("h: %.4f"), hori);
	direction.Y = hori;
}

void ARealPlayer::Vertical(const FInputActionValue& value)
{
	verti = value.Get<float>();
	UE_LOG(LogTemp, Warning, TEXT("h: %.4f"), verti);
	direction.X = verti;
}

void ARealPlayer::Turn(float value){
	me->AddControllerYawInput(value);
}

void ARealPlayer::LookUp(float value){
	me->AddControllerPitchInput(value);
}