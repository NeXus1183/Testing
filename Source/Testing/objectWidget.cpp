// Fill out your copyright notice in the Description page of Project Settings.


#include "objectWidget.h"

#include "buttonTest.h"
#include "DataAssetTest2.h"
#include "InventoryTest.h"

void UobjectWidget::followMouse()
{
	if (GetWorld()->GetFirstPlayerController() != nullptr)
	{
		if (isSnapping == false)
		{
			float mousePosX;
			float mousePosY;
			GetWorld()->GetFirstPlayerController()->GetMousePosition(mousePosX, mousePosY);
			FVector2D followPos = FVector2D(mousePosX, mousePosY);
			currentPos = followPos;
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("MouseX is: %f"), mousePosX));
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("MouseY is: %f"), mousePosY));
		}
		SetPositionInViewport(currentPos);
	}
}

void UobjectWidget::NativePreConstruct()
{
	if (derivedAsset != nullptr && objectToSpawn != nullptr)
	{
		FMargin toSet = FMargin(spacing.X/2, spacing.Y/2, spacing.X/2, spacing.Y/2);	
		parentPanel->SetSlotPadding(toSet);
		for (int i = 0; i < derivedAsset->toOccupy.Num(); i++)
		{
			if (parentPanel != nullptr)
			{
				UUserWidget* newTile = CreateWidget<UUserWidget>(GetWorld(), objectToSpawn);
				parentPanel->AddChildToUniformGrid(newTile, -derivedAsset->toOccupy[i].Y, derivedAsset->toOccupy[i].X);
			}
		}
	}
}

void UobjectWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (isLocked == false)
	{
		followMouse();
	}
}

void UobjectWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
}

void UobjectWidget::toggleOverOff()
{
	isOver = false;
}

void UobjectWidget::toggleOverOn()
{
	isOver = true;
}

void UobjectWidget::toggleSelectedOn()
{
	isSelected = true;
}

void UobjectWidget::toggleSelectedOff()
{
	isSelected = false;
}

void UobjectWidget::toggleSnappingOn()
{
	isSnapping = true;
}

void UobjectWidget::toggleSnappingOff()
{
	isSnapping = false;
}

bool UobjectWidget::getIsOver()
{
	return isOver;
}

bool UobjectWidget::getIsSelected()
{
	return isSelected;
}

bool UobjectWidget::getIsSnapping()
{
	return isSnapping; 
}

FVector2D UobjectWidget::getCurPos()
{
	return currentPos;
}

void UobjectWidget::setCurPos(FVector2D toSet)
{
	currentPos = toSet;
}

void UobjectWidget::setLock(bool toSet)
{
	isLocked = toSet;
}

bool UobjectWidget::getLock()
{
	return isLocked;
}
