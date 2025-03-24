// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BnCPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class NBC_BULLSANDCOWS_API ABnCPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	
	ABnCPlayerState();

	UFUNCTION(BlueprintCallable)
	void SetPlayerChance(int chance);
	UFUNCTION(BlueprintCallable)
	int32 GetPlayerChance();
	UFUNCTION(BlueprintCallable)
	void SetPlayerScore(int playerscore);
	UFUNCTION(BlueprintCallable)
	int32 GetPlayerScore();


	// for Replication
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditAnywhere, Replicated, BlueprintReadWrite)
	bool bCanInput;
	UPROPERTY(EditAnywhere, Replicated, BlueprintReadWrite)
	bool bHasNoChance;

private:
	
	UPROPERTY(EditAnywhere, Replicated)
	int32 RemainingAttempts;
	UPROPERTY(EditAnywhere, Replicated)
	int32 PlayerScore;

};
