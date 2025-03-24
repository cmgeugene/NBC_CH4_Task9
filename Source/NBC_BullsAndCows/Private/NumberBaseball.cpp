// Fill out your copyright notice in the Description page of Project Settings.


#include "NumberBaseball.h"

FString UNumberBaseball::SecretNumber = "";
TArray<int32> UNumberBaseball::Numbers = {};
bool UNumberBaseball::bIsPlaying = false;


FString UNumberBaseball::GenerateSecretNumber()
{
	// 정답 초기화
	SecretNumber = "";
	Numbers = {};
	
	// 정수 배열 Number의 크기가 3이 될 때까지 반복
	// 없는 수라면 Numbers에 추가
	int Num = 0;
	while (Numbers.Num() < 3)
	{
		Num = FMath::RandRange(1, 9);
		if (!Numbers.Contains(Num)) Numbers.Add(Num);
	}
	
	// 정수배열의 정수를 문자열로 바꿔 정답에 추가
	for (int i = 0; i < Numbers.Num(); i++)
	{
		SecretNumber += FString::FromInt(Numbers[i]);
	}
	
	// 디버깅용 로그
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

	// 플레이어 입력을 담을 배열 선언
	TArray<int> PlayerGuess;
	PlayerGuess.SetNum(3);
	// 플레이어의 입력을 한 자리씩 나누기
	for (int i = 0; i < 3; i++)
	{
		FString MidNum = guess.Mid(i + 1, 1);
		PlayerGuess[i] = FCString::Atoi(*MidNum);
	}
	
	// Ball, Strike 판정
	for (int i = 0; i < PlayerGuess.Num(); i++)
	{
		//포함하고 있는 경우
		if (Numbers.Contains(PlayerGuess[i]))
		{
			// 포함하고 있고, 자리수도 같은 경우 bulls++
			if (PlayerGuess[i] == Numbers[i])
			{
				bulls++;
			}
			// 포함하고 있지만 자리수는 다른 경우 cows++
			else if (PlayerGuess[i] != Numbers[i])
			{
				cows++;
			}
		}
	}
	
	// 디버깅용 로그
	UE_LOG(LogTemp, Display, TEXT("Guess Result : %i Strikes,  %i Balls."), bulls, cows);
}

bool UNumberBaseball::IsValidGuess(const FString& guess)
{
	// 1. '/'로 시작하는가
	if (guess[0] != '/') return false;

	// 2. '/123' 의 4자리인가
	if (guess.Len() != 4) return false;

	// 3. 뒤의 3자리가 숫자인가
	for (int i = 1; i < guess.Len(); i++)
	{
		if (!FChar::IsDigit(guess[i])) return false;
	}

	// 4. 3자리 숫자가 겹치지 않는가
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