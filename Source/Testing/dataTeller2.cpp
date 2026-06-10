// Fill out your copyright notice in the Description page of Project Settings.


#include "dataTeller2.h"


// Sets default values
AdataTeller2::AdataTeller2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AdataTeller2::BeginPlay()
{
	Super::BeginPlay();
	//FTimerHandle timerHandle;	
	//TimerManager.SetTimer(timerHandle, this, &AdataTeller2::debugTest, 6, false, 6);
}

void AdataTeller2::debugTest()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("ToCheck Name is: %s"), *toCheck->name));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("ToCheck stack count is: %i"), toCheck->stackVal));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("ToCheck damage is: %f"), toCheck->damage));
}

// Called every frame
void AdataTeller2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (timer > 0)
	{
		timer -= DeltaTime;
	}
	else
	{
		//debugTest();
	}
}

