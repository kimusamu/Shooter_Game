// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);

	if (HUD != nullptr) {
		HUD->AddToViewport();
	}
}


void AMyPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinnder)
{
	Super::GameHasEnded(EndGameFocus, bIsWinnder);

	HUD->RemoveFromViewport();

	if (bIsWinnder) {
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);

		if (WinScreen != nullptr) {
			WinScreen->AddToViewport();
		}
	}

	else {
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);

		if (LoseScreen != nullptr) {
			LoseScreen->AddToViewport();
		}
	}

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}