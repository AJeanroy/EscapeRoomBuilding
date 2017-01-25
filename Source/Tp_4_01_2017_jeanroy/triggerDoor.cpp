// Fill out your copyright notice in the Description page of Project Settings.

#include "Tp_4_01_2017_jeanroy.h"
#include "triggerDoor.h"


// Sets default values for this component's properties
UtriggerDoor::UtriggerDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UtriggerDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UtriggerDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

