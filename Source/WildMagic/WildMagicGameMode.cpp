// Copyright Epic Games, Inc. All Rights Reserved.

#include "WildMagicGameMode.h"
#include "WildMagicPlayerController.h"
#include "WildMagicCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWildMagicGameMode::AWildMagicGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AWildMagicPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}