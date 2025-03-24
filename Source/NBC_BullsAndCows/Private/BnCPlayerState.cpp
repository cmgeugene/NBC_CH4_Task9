// Fill out your copyright notice in the Description page of Project Settings.


#include "BnCPlayerState.h"
#include "Net/UnrealNetwork.h" // 멤버변수 replication에 필요

ABnCPlayerState::ABnCPlayerState()
{
	RemainingAttempts = 3;
	PlayerScore = 0;
	bCanInput = false;
	bHasNoChance = false;
}

void ABnCPlayerState::SetPlayerChance(int chance)
{
	RemainingAttempts = chance;
}

int32 ABnCPlayerState::GetPlayerChance()
{
	return RemainingAttempts;
}

void ABnCPlayerState::SetPlayerScore(int playerscore)
{
	PlayerScore = playerscore;
}

int32 ABnCPlayerState::GetPlayerScore()
{
	return PlayerScore;
}

void ABnCPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps); 

	DOREPLIFETIME(ABnCPlayerState, RemainingAttempts); 
	DOREPLIFETIME(ABnCPlayerState, PlayerScore);
	DOREPLIFETIME(ABnCPlayerState, bHasNoChance);
	DOREPLIFETIME(ABnCPlayerState, bCanInput);
}