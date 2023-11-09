// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "FPSUserWidget.h"
#include "VGP221Fall2023GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VGP221FALL2023_API AVGP221Fall2023GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG UI")
	TSubclassOf<UFPSUserWidget> StartingWidgetClass;

	UPROPERTY()
	UFPSUserWidget* CurrentWidget;

	UFUNCTION(BlueprintCallable, Category = "UMG UI")
	void ChangeMenuWidget(TSubclassOf<UFPSUserWidget> NewWidgetClass);
};
