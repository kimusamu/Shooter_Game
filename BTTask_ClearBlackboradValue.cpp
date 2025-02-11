// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearBlackboradValue.h"
#include "BehaviorTree//BlackboardComponent.h"

UBTTask_ClearBlackboradValue::UBTTask_ClearBlackboradValue()
{
	NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_ClearBlackboradValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult::Succeeded;
}
