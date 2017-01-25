// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_BuildingEscapRoom.h"
#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	//OpenAngle = -120.0f;

	// ...
}

// Called when the game starts
void UOpenDoor::BeginPlay(){
	Super::BeginPlay();

	Owner = GetOwner();
	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ){
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (!PressurePlate) {
		return;
	}

	if (PressurePlate->IsOverlappingActor(ActorThatOpen)) {
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > Delay) {
		CloseDoor();
	}

}

void UOpenDoor::OpenDoor() {
	
	
		Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
	
	
}

void UOpenDoor::CloseDoor() {
	
	
		Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	
}

