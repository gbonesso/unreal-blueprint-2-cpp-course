// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestInfo.generated.h"

/**
 * BlueprintType: Variables in Blueprints can be of this type
 * In the tutorial the struct name was UQuestInfo, but the U prefix is used for classes, not structs
 */
USTRUCT(BlueprintType)
struct BLUEPRINTSTOCPP_API FQuestInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// FName is a type that is used to store names in Unreal Engine, almost like FString but more optimized
	FName QusetId; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Progress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ProgressTotal;
};
