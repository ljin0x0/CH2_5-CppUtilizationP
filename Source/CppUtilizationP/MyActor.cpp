// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
	: positionX(0)
	, positionY(0)
	, positionZ(0)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay() //시작 시 한 번 실행
{
	Super::BeginPlay(); // 부모 기능 실행

	StartLocation = FVector(0, 50, 0); //시작 위치 0, 50, 0
	SetActorLocation(StartLocation); //액터의 위치를 시작위치로 설정

	positionX = StartLocation.X;
	positionY = StartLocation.Y;
	positionZ = StartLocation.Z;

}

 //Called every frame
void AMyActor::Tick(float DeltaTime) //매 프레임마다 호출
{
	Super::Tick(DeltaTime); // 부모 클래스의 Tick도 실행

	move(20 * DeltaTime, 0, 20 * DeltaTime); //X방향 20, Y방향 0, Z방향 20 으로 프레임마다 이동


}

void AMyActor::move(float deltaX, float deltaY, float deltaZ) //액터 이동
{
	FVector NewLocation = GetActorLocation(); //현재 액터 위치 가져옴

	NewLocation.X += deltaX; //기존 위치에 이동할 거리 더해서 새로운 위치 구함
	NewLocation.Y += deltaY;
	NewLocation.Z += deltaZ;
	
	SetActorLocation(NewLocation); //새로 구한 위치 액터에 적용
}

