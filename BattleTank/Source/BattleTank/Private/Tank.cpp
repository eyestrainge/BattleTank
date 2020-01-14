// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/*auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: Tank C++ Construct"), *TankName)*/

	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
//void ATank::BeginPlay()
//{
//	Super::BeginPlay(); // Needed for BP Begin Play to run!
//
//	auto TankName = GetName();
//	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: Tank C++ BeginPlay"), *TankName)
//}
