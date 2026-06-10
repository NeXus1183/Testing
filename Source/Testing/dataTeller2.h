// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataAssetTest2.h"
#include "InventoryTest.h"
#include "dataTeller2.generated.h"

UCLASS()
class TESTING_API AdataTeller2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AdataTeller2();

protected:
	// Called when the game starts or when spawned
	float timer = 5.0f;
	virtual void BeginPlay() override;
	void debugTest();
	//FTimerManager& TimerManager = GetWorldTimerManager();

public:	
	// Called every frame
	UPROPERTY(EditAnywhere, blueprintReadWrite)
	TObjectPtr<UDataAssetTest2> toCheck;
	virtual void Tick(float DeltaTime) override;
};
