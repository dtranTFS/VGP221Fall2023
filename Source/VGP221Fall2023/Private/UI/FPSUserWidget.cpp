// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FPSUserWidget.h"

void UFPSUserWidget::NativeConstruct()
{
	SetHealthBar(1.0);
	SetScore(0);

	if (ButtonWidgetRef) {
		for (int i = 0; i < 4; i++)
		{
			UUserWidget* widget = CreateWidget(this, ButtonWidgetRef);
			ButtonContainer->AddChildToVerticalBox(widget);

			UButtonWidget* button = Cast<UButtonWidget>(widget);
			button->SetText(i);
		}
	}
}

void UFPSUserWidget::SetHealthBar(float percentage)
{
	if (!HealthBar) return; // Same thing as if(HealthBar != nullptr)

	HealthBar->SetPercent(percentage);
}

void UFPSUserWidget::SetScore(int scoreAmount)
{
	if (!ScoreText) return;

	UIScore += scoreAmount;
	ScoreText->SetText(FText::FromString("Score: " + FString::FromInt(UIScore)));
}
