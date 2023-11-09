// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectable.h"
#include "Coin.generated.h"

/**
 * 
 */
UCLASS()
class VGP221FALL2023_API ACoin : public ACollectable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnCollect() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CoinMesh;
};
