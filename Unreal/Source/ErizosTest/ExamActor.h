// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExamActor.generated.h"

USTRUCT(BlueprintType)
struct FCustomMargin
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Left;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Top;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Right;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Bottom;

public:
	FCustomMargin()
		: Left(0.f)
		, Top(0.f)
		, Right(0.f)
		, Bottom(0.f)
	{ }

public:
	FVector2D GetDesiredSize() const
	{
		return FVector2D(Left + Right, Top + Bottom);
	}
};

UCLASS(Blueprintable, BlueprintType)
class ERIZOSTEST_API AExamActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AExamActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void FitBackgroundToActor(class USceneComponent* Background, FCustomMargin Margin);

private:
	static constexpr float ScaleFactor = 0.02f;
};
