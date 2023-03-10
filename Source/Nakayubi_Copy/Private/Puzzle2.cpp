// Fill out your copyright notice in the Description page of Project Settings.


#include "Puzzle2.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APuzzle2::APuzzle2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

#pragma region Mesh Component
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(meshComp);
	ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMesh(TEXT(" /Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	//if found
	if (cubeMesh.Succeeded()) {
		meshComp->SetStaticMesh(cubeMesh.Object);
	}
#pragma endregion
}

// Called when the game starts or when spawned
void APuzzle2::BeginPlay()
{
	Super::BeginPlay();

#pragma region Puzzle Interaction
	//reset original position
	originalPosition = GetActorLocation();
#pragma endregion

	//deprecated
	//puzzle2State = EPuzzle2State::Unchanged;
}

// Called every frame
void APuzzle2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

#pragma region Puzzle Interaction
	if (isClicked) {
		MovePosition();
		//UE_LOG(LogTemp, Warning, TEXT("isClicked"));						//Need asterisk because need pointer to print out character
	}
	else {
		MoveToOriginalPosition();
		//UE_LOG(LogTemp, Warning, TEXT("isUnClicked"));						//Need asterisk because need pointer to print out character
	}
#pragma endregion
}

#pragma region Puzzle Interaction
void APuzzle2::MovePosition()
{
	isPuzzleActorState = true;									//change state to true when clicked from AMyCharacter

	SetActorLocation(originalPosition + offsetPosition);		//move actor by offset
}

void APuzzle2::MoveToOriginalPosition()
{
	isPuzzleActorState = false;									//change state to true when clicked from AMyCharacter

	SetActorLocation(originalPosition);							//move character back to original position
}
#pragma endregion
