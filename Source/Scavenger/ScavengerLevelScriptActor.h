// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "ScavengerLevelScriptActor.generated.h"

class ACCTVActor;

/**
 * 
 */
UCLASS()
class SCAVENGER_API AScavengerLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Camera")
	TArray<ACCTVActor*> Cameras;

public:
	TArray<ACCTVActor*> GetCameraList() { return Cameras; }
	
};
