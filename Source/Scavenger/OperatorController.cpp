// Fill out your copyright notice in the Description page of Project Settings.


#include "OperatorController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/World.h"
#include "ButtonComponent.h"
#include "GameFramework/Character.h"
#include "RobotCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void AOperatorController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
	bAutoManageActiveCameraTarget = false;

	//spawn robot
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = this;
	RobotCharacter = GetWorld()->SpawnActor<ARobotCharacter>(RobotClass, SpawnPoint, SpawnRotation, SpawnParams);
	RobotCharacter->SpawnDefaultController();

	ForwardVector = RobotCharacter->GetActorForwardVector();
}

void AOperatorController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeDelta = DeltaTime;
	FHitResult HitResult;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit && HitResult.GetActor()->ActorHasTag(TEXT("Controller")))
		CachedButtonActor = HitResult.GetActor();
	else
		CachedButtonActor = nullptr;

	if (bIsAdjustTorso && RobotCharacter->GetVelocity().Size() > 20)
	{
		float TurnValue = (TurnDirection > 0) ? -360 * DeltaTime: 360 * DeltaTime;
		if (TurnDirection < 2.0f && TurnDirection > -2.0f) {
			TurnValue = -TurnDirection;
			bIsAdjustTorso = false;
		}
		Turn(TurnValue);
	}
}

void AOperatorController::Move()
{
	// TODO: Move Backwards do not follow the forward vector
	if (!RobotCharacter)
		return;
	
	int Value = ButtonComponent->GetButtonMapping();
	float MoveSpeed = (Value > 0) ? 300 : 200;
	RobotCharacter->GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;
	FVector TrueForwardVector = RobotCharacter->GetActorForwardVector();
	
	// make the forward vector of the robot character the turn direction
	if (!bIsAdjustTorso && TurnDirection != 0)
	{
		bIsAdjustTorso = true;
		FRotator NewRotation(0, TurnDirection, 0);
		ForwardVector = NewRotation.RotateVector(TrueForwardVector);
	}
	float Angle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(TrueForwardVector, ForwardVector)));

	if (Angle > 3.5f) 
	{
		float TurnValue = (TurnDirection > 0) ? 360 * TimeDelta : -360 * TimeDelta;
		FRotator NewRotation(0, TurnValue, 0);
		RobotCharacter->SetActorRotation(NewRotation + RobotCharacter->GetActorRotation());
	}
	else if (Angle > 0 && Angle < 3.5f)
	{
		float TurnValue = (TurnDirection > 0) ? Angle : -Angle;
		FRotator NewRotation(0, TurnValue, 0);
		RobotCharacter->SetActorRotation(NewRotation + RobotCharacter->GetActorRotation());
	}
	RobotCharacter->MoveForward(Value, ForwardVector);
}

void AOperatorController::Turn(float Value)
{
	if (!RobotCharacter)
		return;
	TurnDirection += Value;
	TurnDirection = FMath::Clamp(TurnDirection, -179.99f, 179.99f);
	RobotCharacter->SetYaw(TurnDirection);
}

void AOperatorController::Click()
{
	if(!CachedButtonActor)
		return;
	ButtonComponent = CachedButtonActor->FindComponentByClass<UButtonComponent>();
	if(!ButtonComponent)
			return;

	switch (ButtonComponent->GetButtonAction())
	{
		case EButtonActions::RB_Move:
			Move();
			break;
		case EButtonActions::RB_Turn:
			Turn(ButtonComponent->GetButtonMapping());
			bIsAdjustTorso = false;
			break;
		case EButtonActions::RB_Interact:
			UE_LOG(LogTemp, Warning, TEXT("RB_Interact"));
			break;
		case EButtonActions::RB_Highlight:
			UE_LOG(LogTemp, Warning, TEXT("RB_Highlight"));
			break;
		case EButtonActions::RB_Ping:
			UE_LOG(LogTemp, Warning, TEXT("RB_Ping"));
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("Default"));
			break;
	}
}

void AOperatorController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Add Enhanced Input Component
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(ClickAction, ETriggerEvent::Triggered, this, &AOperatorController::Click);
	}
}
