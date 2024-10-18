// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilityFunctions.generated.h"

/**
 * Utils
 */
UCLASS()
class ERIZOSTEST_API UUtilityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Parse a first encountered integer value from string */
	UFUNCTION(BlueprintPure, Category = "0 Tasks")
	static int32 ParseInt(const FString& InString, bool bStrictMode = false);

	/** */
	UFUNCTION(BlueprintCallable , Category = "0 Tasks")
	static void SpiralPrint(int32 Width, int32 Height);
};
