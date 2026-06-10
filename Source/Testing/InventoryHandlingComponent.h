// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryHandlingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class TESTING_API UInventoryHandlingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryHandlingComponent();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawn_Settings)
	TSubclassOf<AActor> toSpawnInventory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawn_Settings)
	FVector spawnOffset;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawn_Settings)
	FRotator spawnRotation;
public:	
	UFUNCTION(BlueprintCallable)
	AActor* spawnObject();
	UFUNCTION(BlueprintCallable)
	FVector2D setCurrentObjectRotation(FVector2D toRotate);
};
