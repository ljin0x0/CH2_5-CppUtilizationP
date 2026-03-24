// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class CPPUTILIZATIONP_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties5
	AMyActor();

	void move(float deltaX, float deltaY, float deltaZ); //액터 위치 이동
	void turn(float deltaPitch, float deltaYaw, float deltaRoll); //액터 회전


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	float positionX; //X 위치
	float positionY; //Y 위치
	float positionZ; //Z 위치

	FVector StartLocation;

};
