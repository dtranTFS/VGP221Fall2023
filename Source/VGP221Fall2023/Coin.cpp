// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"

// Sets default values
ACoin::ACoin()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!CoinMesh) {
		CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
		CoinMesh->SetupAttachment(CollisionComponent);
	}
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));
}

void ACoin::OnCollect()
{
	Super::OnCollect();
	
	RotationRate = CollectRotationRate;
	GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &ACoin::DeathTimerComplete, 0.5f, false);
}

void ACoin::DeathTimerComplete()
{
	AVGP221Fall2023GameModeBase* GameMode = Cast<AVGP221Fall2023GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode) {
		GameMode->CurrentWidget->SetScore(Points);
	}

	Destroy();
}
