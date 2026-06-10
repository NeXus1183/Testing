// Fill out your copyright notice in the Description page of Project Settings.


#include "DataTeller.h"
#include "DataAssetTest2.h"
#include "InventoryTest.h"

// Sets default values
ADataTeller::ADataTeller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADataTeller::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("ToCheck Name is: %s"), *toCheck->name)
	toChange = Cast<UInventoryTest>(UInventoryTest::StaticClass());;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("ToCheck Name is: %s"), *toCheck->name));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("ToCheck stack count is: %i"), toCheck->stackVal));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("ToCheck damage is: %f"), toCheck->damage));
}

// Called every frame
void ADataTeller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


