// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "DoorOpener.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TD_BUILDINGESCAPROOM_API UDoorOpener : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
		float OpenAngle;

	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate;//Set TriggerVolume Editable UE4

	AActor *ActorThatOpen = nullptr;//pawn hérite de actor

	UPROPERTY(EditAnywhere)
		float Delay = 1.0f;

	float LastDoorOpenTime;

	AActor *Owner;

	float GetTotalMassOfActors();

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnCloseRequest;

public:
	// Sets default values for this component's properties
	UDoorOpener();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Méthode ouvrir porte
	void DoorOpener();

	//Méthode ferme porte
	void CloseDoor();

};