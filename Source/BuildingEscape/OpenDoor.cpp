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
	// Set Rotation
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoor::CloseDoor()
{
	// Set Rotation
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
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
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	// Check if it's time to close the door
	if(GetWorld()->GetTimeSeconds() - LastDoorOpenTime >= DoorCloseDelay && Owner->GetActorRotation().Yaw != 0.f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Closing Door"));
		CloseDoor();
	}
}

