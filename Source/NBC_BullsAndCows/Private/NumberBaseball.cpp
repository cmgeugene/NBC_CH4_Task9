// Fill out your copyright notice in the Description page of Project Settings.


#include "NumberBaseball.h"

FString UNumberBaseball::SecretNumber = "";
TArray<int32> UNumberBaseball::Numbers = {};
bool UNumberBaseball::bIsPlaying = false;


FString UNumberBaseball::GenerateSecretNumber()
{
	// ���� �ʱ�ȭ
	SecretNumber = "";
	Numbers = {};
	
	// ���� �迭 Number�� ũ�Ⱑ 3�� �� ������ �ݺ�
	// ���� ����� Numbers�� �߰�
	int Num = 0;
	while (Numbers.Num() < 3)
	{
		Num = FMath::RandRange(1, 9);
		if (!Numbers.Contains(Num)) Numbers.Add(Num);
	}
	
	// �����迭�� ������ ���ڿ��� �ٲ� ���信 �߰�
	for (int i = 0; i < Numbers.Num(); i++)
	{
		SecretNumber += FString::FromInt(Numbers[i]);
	}
	
	// ������ �α�
	UE_LOG(LogTemp, Display, TEXT("Generated Answer : %s"), *SecretNumber);

	return SecretNumber;
}
void UNumberBaseball::SubmitGuess(
	const FString& guess,
	const FString& answer,
	int32& bulls,
	int32& cows) 
{
	bulls = 0;
	cows = 0;

	// �÷��̾� �Է��� ���� �迭 ����
	TArray<int> PlayerGuess;
	PlayerGuess.SetNum(3);
	// �÷��̾��� �Է��� �� �ڸ��� ������
	for (int i = 0; i < 3; i++)
	{
		FString MidNum = guess.Mid(i + 1, 1);
		PlayerGuess[i] = FCString::Atoi(*MidNum);
	}
	
	// Ball, Strike ����
	for (int i = 0; i < PlayerGuess.Num(); i++)
	{
		//�����ϰ� �ִ� ���
		if (Numbers.Contains(PlayerGuess[i]))
		{
			// �����ϰ� �ְ�, �ڸ����� ���� ��� bulls++
			if (PlayerGuess[i] == Numbers[i])
			{
				bulls++;
			}
			// �����ϰ� ������ �ڸ����� �ٸ� ��� cows++
			else if (PlayerGuess[i] != Numbers[i])
			{
				cows++;
			}
		}
	}
	
	// ������ �α�
	UE_LOG(LogTemp, Display, TEXT("Guess Result : %i Strikes,  %i Balls."), bulls, cows);
}

bool UNumberBaseball::IsValidGuess(const FString& guess)
{
	// 1. '/'�� �����ϴ°�
	if (guess[0] != '/') return false;

	// 2. '/123' �� 4�ڸ��ΰ�
	if (guess.Len() != 4) return false;

	// 3. ���� 3�ڸ��� �����ΰ�
	for (int i = 1; i < guess.Len(); i++)
	{
		if (!FChar::IsDigit(guess[i])) return false;
	}

	// 4. 3�ڸ� ���ڰ� ��ġ�� �ʴ°�
	TSet<TCHAR> UniqueNumber;
	for (int i = 1; i < guess.Len(); i++)
	{
		UniqueNumber.Add(guess[i]);
	}
	if (UniqueNumber.Num() != 3) return false;

	return true;
}

FString UNumberBaseball::GetSecretNumber()
{
	return SecretNumber;
}


void UNumberBaseball::SetSecretNumber(FString& NewSecretNumber)
{
	SecretNumber = NewSecretNumber;
}

void UNumberBaseball::SetGameIsPlaying(bool IsPlaying)
{
	bIsPlaying = IsPlaying;
}
bool UNumberBaseball::GetGameIsPlaying()
{
	return bIsPlaying;
}