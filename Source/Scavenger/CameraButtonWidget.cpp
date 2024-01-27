// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraButtonWidget.h"
#include "SystemsWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WidgetComponent.h"

void UCameraButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();
	TArray<AActor*> SystemUiActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("SystemUI"), SystemUiActors);
	CameraBttn->OnClicked.AddDynamic(this, &UCameraButtonWidget::OnCameraBttnClicked);
	UWidgetComponent* WidgetComponent = Cast<UWidgetComponent>(SystemUiActors[0]->GetComponentByClass(UWidgetComponent::StaticClass()));
	SystemsWidget = Cast<USystemsWidget>(WidgetComponent->GetUserWidgetObject());
}

void UCameraButtonWidget::OnCameraBttnClicked()
{
	SystemsWidget->UpdateCameraFeed(CameraID);
}
