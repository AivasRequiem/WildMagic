// Copyright Epic Games, Inc. All Rights Reserved.

#include "WildMagicGameMode.h"
#include "WildMagicPlayerController.h"
#include "WildMagicCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWildMagicGameMode::AWildMagicGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AWildMagicPlayerController::StaticClass();
}