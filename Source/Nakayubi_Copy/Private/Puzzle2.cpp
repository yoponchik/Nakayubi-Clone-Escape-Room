// Fill out your copyright notice in the Description page of Project Settings.


#include "Puzzle2.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APuzzle2::APuzzle2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(meshComp);
	ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMesh(TEXT(" /Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	//if found
	if (cubeMesh.Succeeded()) {
		meshComp->SetStaticMesh(cubeMesh.Object);
	}
}

// Called when the game starts or when spawned
void APuzzle2::BeginPlay()
{
	Super::BeginPlay();
	puzzle2State = EPuzzle2State::Unchanged;

	originalPosition = GetActorLocation();
}

// Called every frame
void APuzzle2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isClicked) {
		MovePosition();
		UE_LOG(LogTemp, Warning, TEXT("isClicked"));						//Need asterisk because need pointer to print out character
	}
	else {
		MoveToOriginalPosition();
		UE_LOG(LogTemp, Warning, TEXT("isUnClicked"));						//Need asterisk because need pointer to print out character
	}

	//switch (puzzle2State) {
	//	case EPuzzle2State::Unchanged:
	//		MoveToOriginalPosition();
	//		break;
	//	case EPuzzle2State::Changed:
	//		MovePosition();
	//		break;
	//	default:
	//		break;
	//}
}

void APuzzle2::MovePosition()
{
	SetActorLocation(originalPosition + offsetPosition);
}

void APuzzle2::MoveToOriginalPosition()
{
	SetActorLocation(originalPosition);
}

