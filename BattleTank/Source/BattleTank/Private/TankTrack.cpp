// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//UE_LOG(LogTemp, Warning, TEXT("Track ticking"))
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	if (TankRoot)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankRoot found @ TickComponent"))
		auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Two tracks
		TankRoot->AddForce(CorrectionForce);
	}
}

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
}