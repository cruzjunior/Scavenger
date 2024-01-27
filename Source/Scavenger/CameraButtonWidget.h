// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CameraButtonWidget.generated.h"

class USystemsWidget;

/**
 * 
 */
UCLASS()
class SCAVENGER_API UCameraButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* CameraBttn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	FString CameraID;

	UFUNCTION()
	void OnCameraBttnClicked();

	USystemsWidget* SystemsWidget;
};
