// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPos.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPos::UWorldPos()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPos::BeginPlay()
{
	Super::BeginPlay();

	// FString Log = TEXT("Hello");
	// FString* PtrLog = &Log; // reference to FString using *

	// (*PtrLog).Len(); // Lets you access components BUT is super messy. Dot operator goes first so we need ( ) to override due to operator precedence
	// PtrLog->Len(); // -> used first, cleaner

	// UE_LOG(LogTemp, Warning, TEXT("%s"), **PtrLog); // de-referencing and using the overloaded operator next to each other in **
	
	FString Name = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetName());

	FString ObjectPosition = GetOwner()->GetActorLocation().ToString();

	UE_LOG(LogTemp, Warning,TEXT("%s is at position: %f"), *Name, *ObjectPosition);
}


// Called every frame
void UWorldPos::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

