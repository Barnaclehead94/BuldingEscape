// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPETHECAVE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;  // * indicates that this is a pointer to a PhysicsHandle component
	UInputComponent* InputComponent = nullptr;

	void Grab();
	void Release();		
	void FindPhysicsHandle();
	void SetupInputComponent();

	// Return the first Actor within reach with a physics body
	FHitResult GetFirstPhysicsBodyInReach() const; // const as we don't want to change what this is hit by ever
};
