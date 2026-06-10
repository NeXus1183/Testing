// Fill out your copyright notice in the Description page of Project Settings.


#include "buttonTest.h"

#include "CachedGeometry.h"
#include "InventoryTest.h"

void UbuttonTest::setSelf()
{
	buttonStyle = button->GetStyle();
	startCol = buttonStyle.Normal.TintColor;
	opccupiedColorConverted = FSlateColor(occupiedColor);
	if (OccupiedObject != nullptr)
	{
		toggleOccupied();
	}
}

void UbuttonTest::toggleOccupied()
{
	if (isOccupied == false)
	{
		buttonStyle.Normal.TintColor = occupiedColor;
		isOccupied = true;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Current State is: %s"), (isOccupied ? TEXT("true") : TEXT("false") )));
	}
	else if (isOccupied == true)
	{
		buttonStyle.Normal.TintColor = startCol;
		isOccupied = false;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Current State is: %s"), (isOccupied ? TEXT("true") : TEXT("false") )));
	}
	button->SetStyle(buttonStyle);
}

bool UbuttonTest::getIsOccupied()
{
	return isOccupied;
}

void UbuttonTest::checkRest(bool isClick)
{
	parentInventory->checkOtherGrids(this, isClick);
}

bool UbuttonTest::checkSnapping()
{
	return parentInventory->getSnap();
}





