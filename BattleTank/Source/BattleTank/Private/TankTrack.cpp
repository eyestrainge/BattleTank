// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	if (TankRoot)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankRoot found"))
		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("TankRoot not found"))
	}
}