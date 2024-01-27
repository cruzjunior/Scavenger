// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "AIController.h"
#include "OperatorController.generated.h"

class UButtonComponent;
class ARobotCharacter;

/**
 * 
 */
UCLASS()
class SCAVENGER_API AOperatorController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ClickAction;

protected:
	void Move();
	void Turn(float Value);
	void Click();
	virtual void SetupInputComponent() override;

	AActor* CachedButtonActor;
	AAIController* RobotAIController;
	UButtonComponent* ButtonComponent;
	ARobotCharacter* RobotCharacter;
	float TurnDirection = 0;

	bool bIsAdjustTorso = false;
	FVector ForwardVector;
	float TimeDelta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "controller")
	TSubclassOf<ARobotCharacter> RobotClass;

	// spawn point for the robot
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "controller")
	FVector SpawnPoint = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "controller")
	FRotator SpawnRotation = FRotator(0, 0, 0);


	// spawn point for the robot


	
};
