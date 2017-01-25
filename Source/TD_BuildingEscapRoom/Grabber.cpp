// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_BuildingEscapRoom.h"
#include "Grabber.h"
#define OUT


// Sets default values for this component's properties
UGrabber::UGrabber(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay(){
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ){
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	FVector PlayerVector;
	FRotator PlayerRotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerVector, OUT PlayerRotator);

	DrawDebugLine(GetWorld(), LinkStart, LinkEnd, FColor(255, 0, 0), false, -1, 0, 12.333);

	UE_LOG(LogTemp, Warning, TEXT("Player Vector : %s Player Rotator : %s"), *PlayerVector.ToString(), *PlayerRotator.ToString());
}

