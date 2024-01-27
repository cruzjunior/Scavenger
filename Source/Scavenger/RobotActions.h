// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RobotActions.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ERobotActions : uint8
{
	RA_Move UMETA(DisplayName = "Move"),
	RA_Turn UMETA(DisplayName = "Turn"),
	RA_Attack UMETA(DisplayName = "Attack"),
	RA_Highlight UMETA(DisplayName = "Highlight"),
	RA_Ping UMETA(DisplayName = "Ping")

};
