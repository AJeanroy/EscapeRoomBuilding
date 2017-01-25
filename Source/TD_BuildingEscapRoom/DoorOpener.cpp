// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_BuildingEscapRoom.h"
#include "DoorOpener.h"

#define OUT


// Sets default values for this component's properties
UDoorOpener::UDoorOpener() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	OpenAngle = -60.0f;

	// ...
}


// Called when the game starts
void UDoorOpener::BeginPlay() {
	Super::BeginPlay();

	// ...
	Owner = GetOwner();
	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();

}


// Called every frame
void UDoorOpener::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!PressurePlate) {
		return;
	}
	//Recupére le triggerVolume et si le pawn héritant d'actor passe dans le triggerVolume DoorOpener
	if (GetTotalMassOfActors()>30.0f) {

		DoorOpener();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > Delay) {

		CloseDoor();
	}
}

void UDoorOpener::DoorOpener() {

	//Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
	OnOpenRequest.Broadcast();

}

void UDoorOpener::CloseDoor() {

	//Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	OnCloseRequest.Broadcast();
}

float UDoorOpener::GetTotalMassOfActors() {

	float totalMass = 0.0f;
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	//modification de la référence(cellule) du Tarray

	for (auto &Actor : OverlappingActors) {
		totalMass = totalMass + Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("Mass Actors: %f"), totalMass);
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
	}

	return totalMass;
}