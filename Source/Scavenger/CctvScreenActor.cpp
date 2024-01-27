
// Fill out your copyright notice in the Description page of Project Settings.
#include "CctvScreenActor.h"

// Sets default values
ACctvScreenActor::ACctvScreenActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACctvScreenActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACctvScreenActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<ACCTVActor*> ACctvScreenActor::GetLevelCameraFeeds(FString Level)
{
	if(CameraFeedsMap.Contains(Level))
		return CameraFeedsMap[Level].CameraFeeds;

	return TArray<ACCTVActor*>();
}

