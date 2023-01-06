// Fill out your copyright notice in the Description page of Project Settings.


#include "NumberPuzzle.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "MyPlayer.h"

// Sets default values
ANumberPuzzle::ANumberPuzzle()
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
void ANumberPuzzle::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ANumberPuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!isClicked){return;}

	int32 tempCount = count;

	tempCount %= 9;

	UE_LOG(LogTemp, Warning, TEXT("Count: %d"), tempCount);

}
