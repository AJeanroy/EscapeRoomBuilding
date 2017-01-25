// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCloseRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TP_4_01_2017_JEANROY_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OpenDoor();

	void CloseDoor();

	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
		FOnCloseRequest OnCloseRequest;


private:


	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float TriggerMass = 30.0f;

	UPROPERTY(EditAnywhere)
		bool isUnlocked = false;

	//AActor *ActorThatOpens; //Remeber pawn inherits from actor
	//the owning door
	AActor *owner = nullptr;

	//return total mass in kg
	float GetTotalMassOfActorsOnPlate();

		
	
};
