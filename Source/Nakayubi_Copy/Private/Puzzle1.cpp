// Fill out your copyright notice in the Description page of Project Settings.


#include "Puzzle1.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "MyPlayer.h"


// Sets default values
APuzzle1::APuzzle1()
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
void APuzzle1::BeginPlay(){
	Super::BeginPlay();

#pragma region Material Initialization
	//save current material color vector
	UMaterialInterface* iMat = meshComp->GetMaterial(0);
	FHashedMaterialParameterInfo param = FHashedMaterialParameterInfo(TEXT("myColor"));

	//Assign vector parameter from the Material interface to initColor; making the material[0] in the static mesh component as init color
	iMat->GetVectorParameterValue(param, initColor);

	//Create Material Instance Dynamic object from Material instance
	dynamicMat = UMaterialInstanceDynamic::Create(iMat, this);

	//set dynamic Material in the mesh component
	if (dynamicMat != nullptr) {
		meshComp->SetMaterial(0, dynamicMat);
	}
#pragma endregion

#pragma region PuzzleState
	puzzleState = EPuzzleState::Unchanged;

	//switch (puzzleState) {
	//	case EPuzzleState::Unchanged:
	//		ChangeToOriginalColor();
	//		break;
	//	case EPuzzleState::Changed:
	//		ChangeMaterialColor();
	//		break;
	//	default:
	//		break;
	//}
#pragma endregion

#pragma region Debug Switch
	if (puzzleState == EPuzzleState::Unchanged) {
		UE_LOG(LogTemp, Warning, TEXT("puzzleState = Unchanged"));
	}
	else if (puzzleState == EPuzzleState::Changed) {
		UE_LOG(LogTemp, Warning, TEXT("puzzleState = Changed"));
	}
#pragma endregion

}

void APuzzle1::ChangeToOriginalColor() {
	dynamicMat->SetVectorParameterValue(TEXT("myColor"), (FVector4)initColor);

	#pragma region Debug 
	UE_LOG(LogTemp, Warning, TEXT("ChangeToOriginalColor Called (APuzzle1::ChangeToOriginalColor)"));						//Need asterisk because need pointer to print out character
	#pragma endregion
}

void APuzzle1::ChangeMaterialColor() {
	dynamicMat->SetVectorParameterValue(TEXT("myColor"), (FVector4)FLinearColor::Red);
	
#pragma region Debug 
	UE_LOG(LogTemp, Warning, TEXT("ChangeMaterialColor Called (APuzzle1::ChangeMaterialColor)"));						//Need asterisk because need pointer to print out character
#pragma endregion
}


// Called every frame
void APuzzle1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (puzzleState) {
		case EPuzzleState::Unchanged:
			ChangeToOriginalColor();
			break;
		case EPuzzleState::Changed:
			ChangeMaterialColor();
			break;
		default:
			break;
	}

}
