// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CctvScreenActor.generated.h"

class ACCTVActor;

USTRUCT()
struct FCameraFeeds
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<ACCTVActor*> CameraFeeds;
};

UCLASS()
class SCAVENGER_API ACctvScreenActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACctvScreenActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "CCTV")
	TMap<FString, FCameraFeeds> CameraFeedsMap;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<ACCTVActor*> GetLevelCameraFeeds(FString Level);

};
