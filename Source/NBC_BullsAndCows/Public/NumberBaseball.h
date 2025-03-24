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
	// ���� ����
	UFUNCTION(BlueprintCallable)
	static FString GenerateSecretNumber();
	// ���� ����
	UFUNCTION(BlueprintCallable)
	static void SubmitGuess(
		const FString& guess, 
		const FString& answer, 
		int32& bulls, 
		int32& cows);
	// �ùٸ� �Է����� �˻�
	UFUNCTION(BlueprintCallable)
	static bool IsValidGuess(const FString& guess);
	
	// ���信 ���� getter�� settter
	UFUNCTION(BlueprintCallable)
	static FString GetSecretNumber();
	UFUNCTION(BlueprintCallable)
	static void SetSecretNumber(FString& NewSecretNumber);
	// ���� �÷��� �÷��� getter/setter -
	UFUNCTION(BlueprintCallable)
	static void SetGameIsPlaying(bool IsPlaying);
	UFUNCTION(BlueprintCallable)
	static bool GetGameIsPlaying();
	
private:

	// ����
	static FString SecretNumber;
	// ���� �迭
	static TArray<int32> Numbers;
	// ���� ���� ���� �÷���
	static bool bIsPlaying;

};
