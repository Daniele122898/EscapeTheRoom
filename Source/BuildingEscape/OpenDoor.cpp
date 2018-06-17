// Copyright Argonau Developments 2018

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UOpenDoor::OpenDoor()
{
	// Owning Actor
	AActor* Owner = GetOwner();
	// Create a rotator
	FRotator NewRotation = FRotator(0.f, -OpenAngle, 0.f);
	// Set Rotation
	Owner->SetActorRotation(NewRotation);
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume 
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) // If ActorThatOpens is in the volume
	{
		OpenDoor();
	}
}

