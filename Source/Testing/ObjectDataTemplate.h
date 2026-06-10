// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Class.h"
#include "ObjectDataTemplate.generated.h"

class UDataAssetTest2;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FObjectDataTemplate
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, blueprintReadWrite)
	TObjectPtr<UDataAssetTest2> dataAssetToUse;
	UPROPERTY(EditAnywhere, blueprintReadWrite)
	TArray<FVector2D> rotatedPosis;
	UPROPERTY(EditAnywhere, blueprintReadWrite)
	int startGridIndex;
	UPROPERTY(EditAnywhere, blueprintReadWrite)
	FVector objectPos;
	UPROPERTY(EditAnywhere, blueprintReadWrite)
	FVector objectRotation;
public:
};
