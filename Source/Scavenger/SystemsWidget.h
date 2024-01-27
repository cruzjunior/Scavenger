// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "SystemsWidget.generated.h"

class ACCTVActor;
class UCameraButtonWidget;

/**
 * 
 */
UCLASS()
class SCAVENGER_API USystemsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateCameraFeed(FString Key);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SystemsWidget", meta = (AllowPrivateAccess = "true"))
	TArray<FString> CameraID;

	TMap<FString, ACCTVActor*> CameraFeeds;

	ACCTVActor* CurrentCctv;

	UPROPERTY(EditAnywhere, Category = "SystemsWidget")
	FString CameraTag;

	virtual void NativeConstruct() override;
	
};
