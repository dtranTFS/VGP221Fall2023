// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "ButtonWidget.h"
#include "FPSUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221FALL2023_API UFPSUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
		UVerticalBox* ButtonContainer;

	UPROPERTY(meta = (BindWidget))
		UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* ScoreText;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UButtonWidget> ButtonWidgetRef;
	
	UFUNCTION()
		void SetHealthBar(float percentage);

	UFUNCTION()
		void SetScore(int scoreAmount);

private:
	int UIScore = 0;
};
