// Fill out your copyright notice in the Description page of Project Settings.


#include "CCTVActor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ACCTVActor::ACCTVActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;
	CameraComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCaptureComponent2D"));
	CameraComponent->SetupAttachment(StaticMeshComponent);
}

// Called when the game starts or when spawned
void ACCTVActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACCTVActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACCTVActor::SetRenderTarget()
{
	CameraComponent->TextureTarget = RenderTarget;
}

void ACCTVActor::ClearRenderTarget()
{
	CameraComponent->TextureTarget = nullptr;
}

