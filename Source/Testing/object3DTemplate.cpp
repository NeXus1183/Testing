// Fill out your copyright notice in the Description page of Project Settings.

#include "DataAssetTest2.h"
#include "object3DTemplate.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
Aobject3DTemplate::Aobject3DTemplate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	objectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
	UE_LOG(LogTemp, Warning, TEXT("object mesh created"));
	if (objectMesh)
	{
		SetRootComponent(objectMesh);
	}
	if (derivedAsset != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("set to cube array2"));
		for (int i = 0; i < derivedAsset->toOccupy.Num(); i++)
		{
			cubeReps.Add(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube" + i)));
			UE_LOG(LogTemp, Warning, TEXT("set to cube array"));
		}
	}
	else
	{
		cubeReps2.Add(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube")));
		UE_LOG(LogTemp, Warning, TEXT("set to cube array3"));
	}
}

void Aobject3DTemplate::createObject()
{
	cubeReps2.Add(NewObject<UStaticMeshComponent>());
}

void Aobject3DTemplate::followMouse()
{
	if (GetWorld()->GetFirstPlayerController() != nullptr)
	{
		if (isSnapping == false)
		{
			FHitResult HitResult;
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
			FVector ImpactPoint = HitResult.ImpactPoint;
			FVector CameraPosition = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();
			FVector normalizedVec = (ImpactPoint - CameraPosition);
			normalizedVec.Normalize();
			currentPos = (ImpactPoint - normalizedVec * viewDistance);
		}
		SetActorLocation(currentPos);
	}
}	

void Aobject3DTemplate::toggleSelected()
{
	if (isSelected == false)
	{
		isSelected = true;
	}
	else
	{
		isSelected = false;
	}
}

void Aobject3DTemplate::Tick(float DeltaSeconds)
{
	if (isSelected == true)
	{
		followMouse();
	}
}

void Aobject3DTemplate::toggleSnappingOn()
{
	isSnapping = true;
}

void Aobject3DTemplate::toggleSnappingOff()
{
	isSnapping = false;
}

FVector Aobject3DTemplate::getCurPos()
{
	return currentPos;
}

void Aobject3DTemplate::setCurPos(FVector toSet)
{
	currentPos = toSet;
}

void Aobject3DTemplate::setLock(bool toSet)
{
	isLocked = toSet;
}

bool Aobject3DTemplate::getLock()
{
	return isLocked;
}

void Aobject3DTemplate::setDerivedAsset(UDataAssetTest2* toSet)
{
	derivedAsset = toSet;
}

