// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Sound/SlateSound.h"
#include "Styling/SlateColor.h"
#include "Styling/SlateTypes.h"
#include "Styling/SlateBrush.h"
#include "buttonTest.generated.h"


class UInventoryTest;
class UDataAssetTest2;
/**
 * 
 */
UCLASS()
class TESTING_API UbuttonTest : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> button;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FLinearColor occupiedColor;
private:
	bool isOccupied = false;
	FButtonStyle buttonStyle;
	FSlateColor startCol;
	FSlateColor opccupiedColorConverted;
public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UInventoryTest> parentInventory;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UDataAssetTest2> OccupiedObject;
	FVector2D toOriPos;
	UFUNCTION(BlueprintCallable)
	void toggleOccupied();
	UFUNCTION(BlueprintCallable)
	void setSelf();
	UFUNCTION(BlueprintCallable)
	bool getIsOccupied();
	UFUNCTION(BlueprintCallable)
	void checkRest(bool isClick);
	UFUNCTION(BlueprintCallable)
	bool checkSnapping();
};
