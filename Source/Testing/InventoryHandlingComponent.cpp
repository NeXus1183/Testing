// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryHandlingComponent.h"


// Sets default values for this component's properties
UInventoryHandlingComponent::UInventoryHandlingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor* UInventoryHandlingComponent::spawnObject()
{
	if (toSpawnInventory != nullptr)
	{
		FActorSpawnParameters spawnParams;
		AActor* inventoryObject = GetWorld()->SpawnActor<AActor>(toSpawnInventory, spawnOffset, spawnRotation, spawnParams);
		inventoryObject->AttachToActor(this->GetOwner(), FAttachmentTransformRules::KeepRelativeTransform);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Spaned Object Inventory")));
		return inventoryObject;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("No Spaned Object Inventory")));
		return nullptr;
	}
}

FVector2D UInventoryHandlingComponent::setCurrentObjectRotation(FVector2D toRotate)
{
	int tempX = toRotate.Y;
	int tempY = -(toRotate.X);
	FVector2D toReturn = FVector2D(tempX, tempY);
	return toReturn;
}


