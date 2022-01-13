// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WildMagicCharacter.generated.h"

UCLASS(Blueprintable)
class AWildMagicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AWildMagicCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
	
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	void ChangeHealth(int Value);
	void ChangeMana(int Value);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent; // Top down camera
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom; // Camera boom positioning the camera above the character
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld; // A decal that projects to the cursor location.
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	int MaxHealthPoints = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	int HealthPoints = MaxHealthPoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	int MaxManaPoints = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	int ManaPoints = MaxManaPoints;
};
