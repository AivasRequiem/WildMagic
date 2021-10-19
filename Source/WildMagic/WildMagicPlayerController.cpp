// Copyright Epic Games, Inc. All Rights Reserved.

#include "WildMagicPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "WildMagicCharacter.h"
#include "Engine/World.h"

AWildMagicPlayerController::AWildMagicPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AWildMagicPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void AWildMagicPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AWildMagicPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AWildMagicPlayerController::MoveRight);
}

void AWildMagicPlayerController::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		const FVector Direction = FVector(1.0f, 0.0f, 0.0f);
		APawn* const MyPawn = GetPawn();
		// add movement in direction
		if (MyPawn)
		{
			MyPawn->AddMovementInput(Direction, Value);
		}
	}
}

void AWildMagicPlayerController::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		const FVector Direction = FVector(0.0f, 1.0f, 0.0f);
		APawn* const MyPawn = GetPawn();
		// add movement in that direction
		if (MyPawn)
		{
			MyPawn->AddMovementInput(Direction, Value);
		}
	}
}
