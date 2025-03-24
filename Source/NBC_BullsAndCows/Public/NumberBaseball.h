// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NumberBaseball.generated.h"

/**
 * 
 */
UCLASS()
class NBC_BULLSANDCOWS_API UNumberBaseball : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	// 정답 생성
	UFUNCTION(BlueprintCallable)
	static FString GenerateSecretNumber();
	// 정답 판정
	UFUNCTION(BlueprintCallable)
	static void SubmitGuess(
		const FString& guess, 
		const FString& answer, 
		int32& bulls, 
		int32& cows);
	// 올바른 입력인지 검사
	UFUNCTION(BlueprintCallable)
	static bool IsValidGuess(const FString& guess);
	
	// 정답에 대한 getter와 settter
	UFUNCTION(BlueprintCallable)
	static FString GetSecretNumber();
	UFUNCTION(BlueprintCallable)
	static void SetSecretNumber(FString& NewSecretNumber);
	// 게임 플레이 플래그 getter/setter -
	UFUNCTION(BlueprintCallable)
	static void SetGameIsPlaying(bool IsPlaying);
	UFUNCTION(BlueprintCallable)
	static bool GetGameIsPlaying();
	
private:

	// 정답
	static FString SecretNumber;
	// 정답 배열
	static TArray<int32> Numbers;
	// 게임 진행 여부 플래그
	static bool bIsPlaying;

};
