// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/PrimitiveComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h" // Always the last include



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class BLUEPRINTSTOCPP_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	// Constructor
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetMaxGrabLocation() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetHoldLocation() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UPhysicsHandleComponent* GetPhysicsComponent() const;

	// BlueprintImplementableEvent is used to call the function from blueprint
	// there is no implementation in C++ for this function
	// Typicaly needs to be overriden in blueprint
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void NotifyQuestActor(AActor* Actor); 

	// BlueprintNativeEvent is used to call the function from blueprint
	// It has a default implementation in C++
	// It can be overriden in blueprint and the Blueprint can call the C++ implementation (super)
	// Doesn't need to be overriden (implemented) in blueprint
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	// & is used for out parameters
	bool TraceForPhysicsBodies(AActor*& HitActor, UPrimitiveComponent*& HitComponent);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
// Adding variables
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxGrabDistance = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HoldDistance = 100.f;
};
