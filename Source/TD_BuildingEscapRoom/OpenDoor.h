// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_BUILDINGESCAPROOM_API UOpenDoor : public UActorComponent{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)	
		float OpenAngle;
	UPROPERTY(EditAnywhere)		
		ATriggerVolume *PressurePlate=nullptr;
	
	AActor *ActorThatOpen=nullptr;

	UPROPERTY(EditAnywhere)
		float Delay = 1.0f;

	float LastDoorOpenTime;

	AActor *Owner;

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//Méthode ouvrir porte
	void OpenDoor();

	//Méthode fermer porte
	void CloseDoor();
	
};
