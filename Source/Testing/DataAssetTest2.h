// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Vector2D.h"
#include "DataAssetTest2.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TESTING_API UDataAssetTest2 : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int stackVal;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float damage;	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FVector2D> toOccupy;  
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)	
	TObjectPtr<UStaticMesh> visualRep;
};
