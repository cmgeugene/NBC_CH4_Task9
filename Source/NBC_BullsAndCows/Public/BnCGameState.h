// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "BnCGameState.generated.h"

/**
 * 
 */
UCLASS()
class NBC_BULLSANDCOWS_API ABnCGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	ABnCGameState();

	UFUNCTION(BlueprintCallable)
	void SetTimerDuration(float duration);
	UFUNCTION(BlueprintCallable)
	float GetTimerDuration();

	// for Replication
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UPROPERTY(EditAnywhere, Replicated)
	float TimerDuration;
	
	UPROPERTY(EditAnywhere, Replicated)
	float RemainingDuration;

};
