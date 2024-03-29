// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (InFireRange())
	{
		RotateTurret(Tank->GetActorLocation());	
	}
}

void ATower::HandlerDestruction()
{
	Super::HandlerDestruction();
	Destroy();
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorldTimerManager().SetTimer(FireRateTimerHandler, this, &ATower::CheckFireCondition, FireRate, true);
	
}

void ATower::CheckFireCondition()
{
	if (InFireRange())
	{
		Fire();	
	}
}

bool ATower::InFireRange() const
{
	return Tank && FVector::Dist(GetActorLocation(),Tank->GetActorLocation()) <= FireRange;
}
