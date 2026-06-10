// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataAssetTest2.h"
#include "InventoryTest.h"
#include "DataTeller.generated.h"

UCLASS()
class TESTING_API ADataTeller : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADataTeller();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UPROPERTY(EditAnywhere, blueprintReadWrite)
	TObjectPtr<UDataAssetTest2> toCheck;
	TObjectPtr<UInventoryTest> toChange;
	virtual void Tick(float DeltaTime) override;
};
