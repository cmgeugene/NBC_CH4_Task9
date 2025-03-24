// Fill out your copyright notice in the Description page of Project Settings.


#include "BnCGameState.h"
#include "Net/UnrealNetwork.h" // ������� replication�� �ʿ�

ABnCGameState::ABnCGameState()
{
	TimerDuration = 45.0f;
}
void ABnCGameState::SetTimerDuration(float duration)
{
	TimerDuration = duration;
}
float ABnCGameState::GetTimerDuration()
{
	return TimerDuration;
}

void ABnCGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABnCGameState, RemainingDuration);
	DOREPLIFETIME(ABnCGameState, TimerDuration);

}