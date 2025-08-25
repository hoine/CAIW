// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassStateTreeTypes.h"
#include "MassGenerateRandomValue.generated.h"

USTRUCT()
struct FMassMassGenerateRandomValueData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FFloatInterval Interval = FFloatInterval(0, 1);

	UPROPERTY(EditAnywhere, Category = Output)
	float RandomResult = 0;
};

/** Generate random value in the tweakable diapason */
USTRUCT(meta = (DisplayName = "Generate Random Value"))
struct FMassGenerateRandomValue : public FMassStateTreeTaskBase
{
	GENERATED_BODY()

	using FInstanceDataType = FMassMassGenerateRandomValueData;

protected:
	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
};
