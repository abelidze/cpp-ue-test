// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityFunctions.h"
#include "Kismet/KismetSystemLibrary.h"

static bool IsWhitespace(TCHAR Char)
{
	return FChar::IsWhitespace(Char)
		|| FChar::IsLinebreak(Char)
		|| (TEXT("\r")[0] == Char);
}

static bool IsNotInAlphabet(TCHAR Char)
{
	static const TCHAR Alphabet[] = { '-', 0, 0, '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	static constexpr TCHAR AlphabetSize = sizeof(Alphabet) / sizeof(TCHAR);
	return Char < Alphabet[0]
		|| Char > Alphabet[AlphabetSize - 1]
		|| !Alphabet[Char - Alphabet[0]];
}

int32 UUtilityFunctions::ParseInt(const FString& InString, bool bStrictMode /*= false*/)
{
	int32 Base = 0;
	int32 Sign = 1;
	bool IsWhitespaceSkipped = false;
	for (TCHAR Char : InString)
	{
		if (!IsWhitespaceSkipped && IsWhitespace(Char))
		{
			continue;
		}
		IsWhitespaceSkipped = true;
		if (IsNotInAlphabet(Char))
		{
			break;
		}
		if (Char == '-')
		{
			if (Base != 0)
			{
				break;
			}
			else if (Sign < 0)
			{
				return 0;
			}
			Sign = -1;
			continue;
		}
		if (Char == '0' && Base == 0)
		{
			return 0;
		}
		// Overflow. We could return 0, but I prefer to return current result
		if (Base > MAX_int32 / 10)
		{
			break;
		}
		Base = Base * 10 + (Char - '0');
	}
	return Base * Sign;
}

void UUtilityFunctions::SpiralPrint(FGrid Grid)
{
	int32 Height = Grid.Num();
	int32 Width = Grid[0].Cells.Num();
	int32 Top = 0;
	int32 Right = Width - 1;
	int32 Bottom = Height - 1;
	int32 Left = 0;
	int32 Index = 0;
	FString Output;
	while (true)
	{
		if (Left > Right)
		{
			break;
		}
		// TOP
		for (int32 i = Left; i <= Right; ++i)
		{
			Output.AppendInt(Grid[Top].Cells[i]);
			Output.AppendChar(' ');
		}
		if (++Top > Bottom)
		{
			break;
		}
		// RIGHT
		for (int32 i = Top; i <= Bottom; ++i)
		{
			Output.AppendInt(Grid[i].Cells[Right]);
			Output.AppendChar(' ');
		}
		if (Left > --Right)
		{
			break;
		}
		// BOTTOM
		for (int32 i = Right; i >= Left; --i)
		{
			Output.AppendInt(Grid[Bottom].Cells[i]);
			Output.AppendChar(' ');
		}
		if (Top > --Bottom)
		{
			break;
		}
		// LEFT
		for (int32 i = Bottom; i >= Top; --i)
		{
			Output.AppendInt(Grid[i].Cells[Left]);
			Output.AppendChar(' ');
		}
		++Left;
	}
	UKismetSystemLibrary::PrintString(GEngine->GetWorld(), Output, true, true, FLinearColor(1.0f, 0.0f, 0.0f, 1.0f), 10.0f);
}
