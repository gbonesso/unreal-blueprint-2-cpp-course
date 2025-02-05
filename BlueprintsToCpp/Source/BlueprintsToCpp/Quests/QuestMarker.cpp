// Fill out your copyright notice in the Description page of Project Settings.

#include "QuestMarker.h"

AQuestMarker::AQuestMarker()
{
    PrimaryActorTick.bCanEverTick = false;

    Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    // Create a particle system component. CreateDefaultSubobject can only be called in the constructor.
    ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
    
    SetRootComponent(Root);
    // Attach the particle system to the root component. Also can only be called in the constructor.
    ParticleSystem->SetupAttachment(Root);
}



