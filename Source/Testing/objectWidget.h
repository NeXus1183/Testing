// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TaskSyncManager.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "objectWidget.generated.h"

class UDataAssetTest2;
class UInventoryTest;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class TESTING_API UobjectWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Spawn_Settings)
	TObjectPtr<UDataAssetTest2> derivedAsset;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Spawn_Settings)
	TSubclassOf<UUserWidget> objectToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = Spawn_Settings)
	TObjectPtr<UUniformGridPanel> parentPanel;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Spawn_Settings)
	FVector2D spacing;
private:
	bool isOver = false;
	bool isSelected = false;
	bool isSnapping = false;
	bool isLocked = false;
	FVector2D currentPos;
	void followMouse();
public:
	virtual void NativePreConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	UFUNCTION(BlueprintCallable)
	void toggleOverOn();
	UFUNCTION(BlueprintCallable)
	void toggleOverOff();
	UFUNCTION(BlueprintCallable)
	void toggleSelectedOn();
	UFUNCTION(BlueprintCallable)
	void toggleSelectedOff();
	UFUNCTION(BlueprintCallable)
	void toggleSnappingOn();
	UFUNCTION(BlueprintCallable)
	void toggleSnappingOff();
	UFUNCTION(BlueprintCallable)
	bool getIsOver();
	UFUNCTION(BlueprintCallable)
	bool getIsSelected();
	UFUNCTION(BlueprintCallable)
	bool getIsSnapping();
	UFUNCTION(BlueprintCallable)
	FVector2D getCurPos();
	UFUNCTION(BlueprintCallable)
	void setCurPos(FVector2D toSet);
	UFUNCTION(BlueprintCallable)
	void setLock(bool toSet);
	UFUNCTION(BlueprintCallable)
	bool getLock();
};
