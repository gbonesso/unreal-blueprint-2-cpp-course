// Fill out your copyright notice in the Description page of Project Settings.

#include "../BlueprintsToCpp.h"
#include "QuestManager.h"

// Sets default values
AQuestManager::AQuestManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("QuestManager Constructor"));

}

// Called when the game starts or when spawned
void AQuestManager::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("QuestManager BeginPlay"));
	
}

// Called every frame
void AQuestManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("QuestManager Tick"));

}

// _Implementaion is used to define a BP native event in C++
void AQuestManager::CompleteQuest_Implementation(FName QuestId, bool CompleteWholeQuest)
{
	//UE_LOG(LogTemp, Warning, TEXT("QuestManager CompleteQuest"));
	int32 QuestIndex = GetQuestIndex(QuestId);
	FQuestInfo Quest = QuestList[QuestIndex];
	if(CompleteWholeQuest)
	{
		QuestList[QuestIndex].Progress = Quest.ProgressTotal;
	}
	else
	{
		QuestList[QuestIndex].Progress = FMath::Min(Quest.Progress + 1, Quest.ProgressTotal);
	}

}

