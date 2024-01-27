// Fill out your copyright notice in the Description page of Project Settings.


#include "SystemsWidget.h"
#include "CCTVActor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"
#include "CameraButtonWidget.h"
#include "Components/Button.h"
#include "CctvScreenActor.h"

void USystemsWidget::UpdateCameraFeed(FString Key)
{
	if(!CameraFeeds.Contains(Key))
		return;
	// get the cctv actor from the map
	ACCTVActor* CCTVActor = Cast<ACCTVActor>(CameraFeeds[Key]);
	if (!CCTVActor)
		return;
	if (CurrentCctv)
	{
		CurrentCctv->ClearRenderTarget();
		CurrentCctv = CCTVActor;
		CurrentCctv->SetRenderTarget();
	}
	else 
	{
		CurrentCctv = CCTVActor;
		CurrentCctv->SetRenderTarget();
	}


}

void USystemsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ACctvScreenActor* CctvScreenActor = Cast<ACctvScreenActor>(UGameplayStatics::GetActorOfClass(GetWorld(), ACctvScreenActor::StaticClass()));
	TArray<ACCTVActor*> CctvActors = CctvScreenActor->GetLevelCameraFeeds("1");
	if(CctvActors.Num() == 0)
		return;

	for(int i = 0; i < CameraID.Num(); i++)
	{
		if (CctvActors[i])
		{
			FString Key = CameraID[i];
			CameraFeeds.Add(Key, CctvActors[i]);
		}
	}
	FString Key = CameraID[0];
	UpdateCameraFeed(Key);
}
