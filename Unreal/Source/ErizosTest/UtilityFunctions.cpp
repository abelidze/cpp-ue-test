// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityFunctions.h"
#include "Kismet/KismetSystemLibrary.h"

int32 UUtilityFunctions::ParseInt(const FString& InString, bool bStrictMode /*= false*/)
{
	int32 Base = 0;
	//if (!InString.IsEmpty() && IsStringValidInteger(StartOf(InString), EndOf(InString), Base))
	//{
	//	const bool bHasWhitespace = HasWhitespaces(SouInStringrce);
	//	const FString NoWhitespace = bHasWhitespace ? RemoveWhitespaces(InString) : FString();
	//	OutVal = FCString::Strtoi(bHasWhitespace ? *NoWhitespace : *Source, NULL, Base);
	//}
	return Base;
}

void UUtilityFunctions::SpiralPrint(int32 Width, int32 Height)
{
	FString Output = "Hello World!";
	UKismetSystemLibrary::PrintString(GEngine->GetWorld(), Output, true, true, FLinearColor(1.0f, 0.0f, 0.0f, 1.0f), 5.0f);
}
