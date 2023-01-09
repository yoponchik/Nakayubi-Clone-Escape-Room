// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

#pragma region Components
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
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	originalPosition = GetActorLocation();					//reset position
}


#pragma region Door Functionality
void ADoor::OpenDoor()
{
	SetActorLocation(originalPosition + offsetPosition);
}

void ADoor::CloseDoor()
{
	SetActorLocation(originalPosition);
}
#pragma endregion


