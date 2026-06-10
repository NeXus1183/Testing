// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "object3DTemplate.generated.h"

class UDataAssetTest2;

UCLASS()
class TESTING_API Aobject3DTemplate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aobject3DTemplate();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Spawn_Settings)
	TObjectPtr<UDataAssetTest2> derivedAsset;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Spawn_Settings)
	FVector2D spacing;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Spawn_Settings)
	float viewDistance;
	UPROPERTY(VisibleAnywhere);
	TObjectPtr<UStaticMeshComponent> objectMesh;
	UPROPERTY(VisibleAnywhere);
	TArray<UStaticMeshComponent*> cubeReps;
	UPROPERTY(VisibleAnywhere);
	TArray<UStaticMeshComponent*> cubeReps2;
private:
	bool isSelected = true;
	bool isSnapping = false;
	bool isLocked = false;
	FVector currentPos;
public:	
	UFUNCTION(BlueprintCallable)
	void createObject();
	UFUNCTION(BlueprintCallable)
	void followMouse();
	UFUNCTION(BlueprintCallable)
	void toggleSelected();
	UFUNCTION(BlueprintCallable)
    void toggleSnappingOn();
    UFUNCTION(BlueprintCallable)
    void toggleSnappingOff();
	UFUNCTION(BlueprintCallable)
	FVector getCurPos();
	UFUNCTION(BlueprintCallable)
	void setCurPos(FVector toSet);
	UFUNCTION(BlueprintCallable)
	void setLock(bool toSet);
	UFUNCTION(BlueprintCallable)
	bool getLock();
	UFUNCTION(BlueprintCallable)
	void setDerivedAsset(UDataAssetTest2* toSet);
	virtual void Tick(float DeltaSeconds) override;
};
