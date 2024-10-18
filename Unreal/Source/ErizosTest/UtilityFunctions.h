// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilityFunctions.generated.h"

/**
 * Utils
 */

USTRUCT(BlueprintType)
struct FGridRow
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> Cells;
};


UCLASS()
class ERIZOSTEST_API UUtilityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	using FGrid = TArray<FGridRow>;

	/** Parse a first encountered integer value from string */
	UFUNCTION(BlueprintPure, Category = "0 Tasks")
	static int32 ParseInt(const FString& InString, bool bStrictMode = false);

	/** Print 2D array in a spiral traverse order */
	UFUNCTION(BlueprintCallable , Category = "0 Tasks")
	static void SpiralPrint(TArray<FGridRow> Grid);
};
