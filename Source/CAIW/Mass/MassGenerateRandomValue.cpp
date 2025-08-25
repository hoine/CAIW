// Fill out your copyright notice in the Description page of Project Settings.


#include "MassGenerateRandomValue.h"

#include "StateTreeExecutionContext.h"

EStateTreeRunStatus FMassGenerateRandomValue::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.RandomResult = FMath::RandRange(InstanceData.Interval.Min, InstanceData.Interval.Max);
	return EStateTreeRunStatus::Succeeded;
}
