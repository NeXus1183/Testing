// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryTest.h"
#include "buttonTest.h"
#include "MyGameInstance.h"
#include "DataAssetTest2.h"

void UInventoryTest::setOtherGrids(UbuttonTest* pressedButton, bool isOccupied)
{
	int oriPressedIndex = 0;
	for (int i = 0; i < parentPanel->GetChildrenCount(); i++)
	{
		if (parentPanel->GetChildAt(i) == pressedButton)
		{
			oriPressedIndex = i;
			if (isOccupied == true)
			{
				oriPressedIndex = (oriPressedIndex + (pressedButton->toOriPos.Y * columns) + (-pressedButton->toOriPos.X));
				currentObject = pressedButton->OccupiedObject;
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Changed Object")));
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Had Pressed index is %i"), oriPressedIndex));
				break;
			}
			break;
		}
	}

	if (currentObject == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("NULL REF TO OBJECT")));
		return;
	}
	for (int j = 0; j < currentObjectToOccupy.Num(); j++)
	{
		int otherOccupy = (oriPressedIndex + (currentObjectToOccupy[j].Y * -columns) + (currentObjectToOccupy[j].X));
		UbuttonTest* otherButton = Cast<UbuttonTest>(parentPanel->GetChildAt(otherOccupy));
		if (isOccupied == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("REACHED HERE")));
		}
		else
		{
			otherButton->OccupiedObject = currentObject;
			otherButton->toOriPos = currentObjectToOccupy[j];
			if (j == currentObjectToOccupy.Num() - 1)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("WE HAVE NO ITEM")));
				currentObject = nullptr;
				otherButton->toggleOccupied();
				break;
			}
		}
		otherButton->toggleOccupied();
	}
}

void UInventoryTest::checkOtherGrids(UbuttonTest* pressedButton, bool isToSet)
{
	int oriPressedIndex = 0;
	if (parentPanel == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("No parent panel")));
		return;
	}
	for (int i = 0; i < parentPanel->GetChildrenCount(); i++)
	{
		if (parentPanel->GetChildAt(i) == pressedButton)
		{
			oriPressedIndex = i;
			break;;
		}
	}
	
	int oriRow = (oriPressedIndex / columns) + 1;
	int oriColumn = (oriPressedIndex - ((oriRow - 1) * columns)) + 1;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Ori check X is %i"), oriColumn));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Ori check Y is %i"), oriRow));

	if (pressedButton->getIsOccupied() == false)
	{
		if (currentObject == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("No objected selected")));
			return;
		}
		for (int j = 1; j < currentObjectToOccupy.Num(); j++)
		{
			int otherRow = oriRow - currentObjectToOccupy[j].Y;
			int otherColumn = oriColumn + currentObjectToOccupy[j].X;
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, FString::Printf(TEXT("Current check X is %i"), otherColumn));
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, FString::Printf(TEXT("Current check Y is %i"), otherRow));
			if ((otherRow <= 0 || otherRow > rows) || (otherColumn <= 0 || otherColumn > columns))
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, FString::Printf(TEXT("Not placable: out of bounds")));
				canSnap = false;
				return;
			}
			int otherIndex = ((otherRow - 1) * columns) + (otherColumn - 1);
			UbuttonTest* otherButton = Cast<UbuttonTest>(parentPanel->GetChildAt(otherIndex));
			if (otherButton->getIsOccupied() == true)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, FString::Printf(TEXT("Not placable: tile there")));
				canSnap = false;
				return;
			}
		}
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Placable")));
		canSnap = true;
	}
	if (isToSet == true)
	{
		setOtherGrids(pressedButton, pressedButton->getIsOccupied());
	}
}

void UInventoryTest::setInventoryInstance()
{	
	toSaveTo->clearButtonInfo();
	for (int i = 0; i < parentPanel->GetChildrenCount(); i++)
	{
		toSaveTo->setButtonInfos(Cast<UbuttonTest>(parentPanel->GetChildAt(i)));
	}
}

void UInventoryTest::getInventoryInstance()
{
	if (toSaveTo == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("No instance")));
		return;
	}
	if (toSaveTo->checkIfInfoEmpyty() == false)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, FString::Printf(TEXT("No info so skipping")));
		return;
	}
	parentPanel->ClearChildren();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, FString::Printf(TEXT("Setting at index: %i"), (i * columns) + j));
			UbuttonTest* newTile = CreateWidget<UbuttonTest>(GetWorld(), toSpawnTile);
			newTile->parentInventory = this;
			newTile->OccupiedObject = toSaveTo->getButtonInfos((i * columns) + j)->OccupiedObject;
			newTile->toOriPos = toSaveTo->getButtonInfos((i * columns) + j)->toOriPos;
			parentPanel->AddChildToUniformGrid(newTile, i, j);
		}
	}
}

bool UInventoryTest::getSnap()
{
	return canSnap;
}

void UInventoryTest::createGrid()
{
	FMargin toSet = FMargin(xSpacing/2, ySpacing/2, xSpacing/2, ySpacing/2);	
	parentPanel->SetSlotPadding(toSet);
	toSaveTo = GetWorld()->GetGameInstance<UMyGameInstance>();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (parentPanel != nullptr)
			{
				UbuttonTest* newTile = CreateWidget<UbuttonTest>(GetWorld(), toSpawnTile);
				newTile->parentInventory = this;
				parentPanel->AddChildToUniformGrid(newTile, i, j);
			}
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, FString::Printf(TEXT("Creating Grid")));
	if (toSaveTo == nullptr )
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("NO INSTNCE SET")));
	}
}

void UInventoryTest::printInstanceHave()
{
	if (toSaveTo == nullptr )
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("NO INSTNCE SET")));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("INSTNCE SET")));
	}
}

void UInventoryTest::setCurObjToOccVec(FVector2D toSet)
{
	currentObjectToOccupy.Add(toSet);
}

void UInventoryTest::clearCurObjToOccVec()
{
	currentObjectToOccupy.Empty();
}

void UInventoryTest::setCurrentObject(UDataAssetTest2* toChange)
{
	currentObject = toChange;
	if (currentObjectToOccupy.IsEmpty() == false)
	{
		currentObjectToOccupy.Empty();
	}
	for (int i = 0; i < currentObject->toOccupy.Num(); ++i)
	{
		currentObjectToOccupy.Add(currentObject->toOccupy[i]);
	}
}

UDataAssetTest2* UInventoryTest::getCurrentObject()
{
	return currentObject;
}

