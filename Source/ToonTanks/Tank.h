// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;
	virtual void HandlerDestruction() override;
	APlayerController* GetTankPlayerController() const { return TankPlayerController; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Tank Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Tank Components")
	class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, Category = "Tank Movement")
	float TankSpeed = 100;
	UPROPERTY(EditAnywhere, Category = "Tank Movement")
	double TurnRate = 100;

	void Move(float Value);
	void Turn(float Value);
	void FollowCursor() const;

	APlayerController* TankPlayerController;
};
