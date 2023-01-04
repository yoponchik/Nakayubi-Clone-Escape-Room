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
void APuzzle1::BeginPlay(){
	Super::BeginPlay();
	
	//puzzle1State = EPuzzle1State::Unchanged;

#pragma region Puzzle Interaction
	isPuzzleActorState = false;

#pragma region Debug Switch
	//if (puzzleState == EPuzzleState::Unchanged) {
	//	UE_LOG(LogTemp, Warning, TEXT("puzzleState = Unchanged"));
	//}
	//else if (puzzleState == EPuzzleState::Changed) {
	//	UE_LOG(LogTemp, Warning, TEXT("puzzleState = Changed"));
	//}
#pragma endregion

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

#pragma endregion
}

#pragma region Puzzle Interaction
void APuzzle1::ChangeToOriginalColor() {
	dynamicMat->SetVectorParameterValue(TEXT("myColor"), (FVector4)initColor);
	#pragma region Debug 
	//UE_LOG(LogTemp, Warning, TEXT("ChangeToOriginalColor Called (APuzzle1::ChangeToOriginalColor)"));						//Need asterisk because need pointer to print out character
	#pragma endregion
}

void APuzzle1::ChangeMaterialColor() {
	dynamicMat->SetVectorParameterValue(TEXT("myColor"), (FVector4)FLinearColor::Red);
#pragma region Debug 
	//UE_LOG(LogTemp, Warning, TEXT("ChangeMaterialColor Called (APuzzle1::ChangeMaterialColor)"));						//Need asterisk because need pointer to print out character
#pragma endregion
}

#pragma endregion


// Called every frame
void APuzzle1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

#pragma region Puzzle Interaction


	if (isClicked) {
		ChangeMaterialColor();
#pragma region Debug 
		//UE_LOG(LogTemp, Warning, TEXT("isClicked"));						//Need asterisk because need pointer to print out character
#pragma endregion 
	}
	else {
		ChangeToOriginalColor();
#pragma region Debug 
		//UE_LOG(LogTemp, Warning, TEXT("isUnClicked"));						//Need asterisk because need pointer to print out character
#pragma endregion 
	}

	//switch (puzzle1State) {
	//	case EPuzzle1State::Unchanged:
	//		ChangeToOriginalColor();
	//		break;
	//	case EPuzzle1State::Changed:
	//		ChangeMaterialColor();
	//		break;
	//	default:
	//		break;
	//}

#pragma region Debug Switch
	//if (puzzle1->puzzleState == EPuzzleState::Unchanged) {
	//	UE_LOG(LogTemp, Warning, TEXT("puzzleState = Unchanged"));
	//}
	//else if (puzzle1->puzzleState == EPuzzleState::Changed) {
	//	UE_LOG(LogTemp, Warning, TEXT("puzzleState = Changed"));
	//}
#pragma endregion

#pragma endregion

}

