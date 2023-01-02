// Copyright Epic Games, Inc. All Rights Reserved.

#include "Nakayubi_CopyGameMode.h"
#include "Nakayubi_CopyCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANakayubi_CopyGameMode::ANakayubi_CopyGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;*/

}
