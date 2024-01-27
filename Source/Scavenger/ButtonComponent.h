// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ButtonComponent.generated.h"


UENUM(BlueprintType)
enum class EButtonActions : uint8
{
	RB_Move UMETA(DisplayName = "Move"),
	RB_Turn UMETA(DisplayName = "Turn"),
	RB_Interact UMETA(DisplayName = "Interact"),
	RB_Highlight UMETA(DisplayName = "Highlight"),
	RB_Ping UMETA(DisplayName = "Ping"),
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SCAVENGER_API UButtonComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UButtonComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// create enum for button actions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Actions")
	EButtonActions ButtonAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Actions")
	int ButtonMapping;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	EButtonActions GetButtonAction() { return ButtonAction; }
	int GetButtonMapping() { return ButtonMapping; }

};
