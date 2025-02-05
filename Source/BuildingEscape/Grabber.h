// Copyright Argonaut Developments 2018

#pragma once

#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	// How far ahead of the player can we reach in cm
	float Reach = 100.f;

	struct RayCastPoints
	{
		FVector StartLocation;
		FVector EndLocation;
	};

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Ray-Cast and grab and what's in reach
	void Grab();

	// Release what has been grabbed
	void Release();

	// Get line end for grabber
	RayCastPoints GetRayCastPoints() const;

	FHitResult GetFirstPhysicsBodyInReach() const;

	void FindPhysicsHandleComponent();

	void SetupInputComponent();
};
