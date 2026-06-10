// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

struct FObjectDataTemplate;
class Aobject3DTemplate;
class UInventoryTest;
class UbuttonTest;
/**
 * 
 */
UCLASS()
class TESTING_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UbuttonTest*> buttonInfos;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UInventoryTest> inventoryAsset;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FObjectDataTemplate> placedBlocksData;
public:
	bool checkIfInfoEmpyty();
	void clearButtonInfo();
	void setButtonInfos(UbuttonTest* toAdd);
	UbuttonTest* getButtonInfos(int indexToCheck);
	UFUNCTION(BlueprintCallable)
	void setPlacedObjects(FObjectDataTemplate toAdd);
	UFUNCTION(BlueprintCallable)
	FObjectDataTemplate getPlacedObjects(int indexToCheck);
	UFUNCTION(BlueprintCallable)
	void clearPlacedObjects();
};
