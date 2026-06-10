// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include "InventoryTest.h"
#include "ObjectDataTemplate.h"

bool UMyGameInstance::checkIfInfoEmpyty()
{
	if (buttonInfos.Num() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UMyGameInstance::clearButtonInfo()
{
	buttonInfos.Reset();
}

void UMyGameInstance::setButtonInfos(UbuttonTest* toAdd)
{
	buttonInfos.Add(toAdd);	
}

UbuttonTest* UMyGameInstance::getButtonInfos(int indexToCheck)
{
	return buttonInfos[indexToCheck];
}

void UMyGameInstance::setPlacedObjects(FObjectDataTemplate toAdd)
{
	placedBlocksData.Add(toAdd);	
}

FObjectDataTemplate UMyGameInstance::getPlacedObjects(int indexToCheck)
{
	return placedBlocksData[indexToCheck];
}

void UMyGameInstance::clearPlacedObjects()
{
	placedBlocksData.Reset();
}


