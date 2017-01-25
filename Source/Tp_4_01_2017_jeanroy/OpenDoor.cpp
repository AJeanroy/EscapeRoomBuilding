// Fill out your copyright notice in the Description page of Project Settings.

#include "Tp_4_01_2017_jeanroy.h"
#include "OpenDoor.h"


#define OUT


// Sets default values for this component's properties
UOpenDoor::UOpenDoor() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;





	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay() {
	Super::BeginPlay();

	// find the owning actor
	owner = GetOwner();
	//ActorThatOpens=GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PressurePlate) {

		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName());
	}





	// ...

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);




	//if the ActorThatOpens is in volume (en commentaire)
	//if(PressurePlate->IsOverlappingActor(ActorThatOpens))

	// Poll the Trigger Volume
	if (GetTotalMassOfActorsOnPlate()>TriggerMass && isUnlocked) {

		OpenDoor();


		//Check if it's time to close the door
	}
	else {


		CloseDoor();

	}



}


void UOpenDoor::OpenDoor() {



	//Create a rotaor
	// FRotator NewRotation=FRotator(0.0f,OpenAngle,0.0f);

	//set the door rotation
	// owner->SetActorRotation(FRotator(0.0f,OpenAngle,0.0f));
	OnOpenRequest.Broadcast();



}

void UOpenDoor::CloseDoor() {




	//set the door rotation
	// owner->SetActorRotation(FRotator(0.0f,CloseAngle,0.0f));
	OnCloseRequest.Broadcast();

}

float UOpenDoor::GetTotalMassOfActorsOnPlate() {

	float TotalMass = 0.0f;

	//Find all the overlapping actors
	TArray<AActor*> OverlappingActors;

	if (!PressurePlate) { return TotalMass; }

	PressurePlate->GetOverlappingActors(OUT OverlappingActors);


	//Iterate through them adding their masses
	for (const auto& Actor : OverlappingActors) {


		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%lf Kg on pressure plate"), TotalMass);
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());


	}

	return TotalMass;



}