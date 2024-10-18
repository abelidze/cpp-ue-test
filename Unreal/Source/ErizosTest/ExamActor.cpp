// Fill out your copyright notice in the Description page of Project Settings.


#include "ExamActor.h"

// Sets default values
AExamActor::AExamActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AExamActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AExamActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AExamActor::FitBackgroundToActor(USceneComponent* Background, FCustomMargin Margin)
{
	if (!Background)
	{
		return;
	}
	if (Background->IsCollisionEnabled())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("[FitBackgroundToActor] Colisions for background should be turned off!"));
	}
	FVector BBoxOrigin;
	FVector BBoxExtent;
	GetActorBounds(true, BBoxOrigin, BBoxExtent);
	// CalculateComponentsBoundingBoxInLocalSpace gives us bbox independent of actor's rotation
	BBoxExtent = CalculateComponentsBoundingBoxInLocalSpace(false).GetExtent();
	FVector2D&& MarginSize = Margin.GetDesiredSize();
	BBoxExtent = FVector(BBoxExtent.Z + MarginSize.Y, BBoxExtent.Y + MarginSize.X, BBoxExtent.X) * ScaleFactor;
	Background->SetRelativeScale3D(BBoxExtent);
	FVector&& MarginOffset = GetTransform().Inverse().InverseTransformVectorNoScale(FVector(0.f, Margin.Right - Margin.Left, Margin.Top - Margin.Bottom));
	Background->SetWorldLocation(BBoxOrigin + MarginOffset, false, nullptr, ETeleportType::TeleportPhysics);
}
