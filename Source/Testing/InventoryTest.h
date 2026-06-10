// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/UniformGridPanel.h"
#include "InventoryTest.generated.h"

class UDataAssetTest2;
class UMyGameInstance;
/**
 * 
 */
UCLASS()
class TESTING_API UInventoryTest : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UUniformGridPanel> parentPanel;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UUserWidget*> objectsAdded;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> toSpawnTile;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawn_Settings)
	int rows;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawn_Settings)
	int columns;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawn_Settings)
	float xSpacing;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawn_Settings)
	float ySpacing;
	UPROPERTY(EditAnywhere, blueprintReadWrite, Category = CurrentObject)
	TObjectPtr<UDataAssetTest2> currentObject;
	UPROPERTY(EditAnywhere, blueprintReadWrite, Category = CurrentObject)
	TArray<FVector2D> currentObjectToOccupy;  
	UPROPERTY(EditAnywhere, blueprintReadWrite, Category = GameInstance)
	TObjectPtr<UMyGameInstance> toSaveTo;
	UPROPERTY(EditAnywhere, blueprintReadWrite, Category = Snapping_Settings)
	bool canSnap;
public:
	UFUNCTION(BlueprintCallable)
	void setCurrentObject(UDataAssetTest2* toChange);
	UFUNCTION(BlueprintCallable)
	UDataAssetTest2* getCurrentObject();
	UFUNCTION(BlueprintCallable)
	void setOtherGrids(UbuttonTest* pressedButton, bool isOccupied);
	void checkOtherGrids(UbuttonTest* pressedButton, bool isToSet);
	UFUNCTION(BlueprintCallable)
	void setInventoryInstance();
	UFUNCTION(BlueprintCallable)
	void getInventoryInstance();
	UFUNCTION(BlueprintCallable)
	bool getSnap();
	UFUNCTION(BlueprintCallable)
	void createGrid();
	UFUNCTION(BlueprintCallable)
	void printInstanceHave();
	UFUNCTION(BlueprintCallable)
	void setCurObjToOccVec(FVector2D toSet);
	UFUNCTION(BlueprintCallable)
	void clearCurObjToOccVec();
};
