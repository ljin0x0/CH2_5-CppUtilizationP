// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
	: positionX(0)
	, positionY(0)
	, positionZ(0)
	, MinValue(-50)
	, MaxValue(50)
	, RandomNumber1(0)
	, RandomNumber2(0)
	, RandomNumber3(0)
	, StartLocation(0)
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

	randomNumber();

}

//Called every frame
void AMyActor::Tick(float DeltaTime) //매 프레임마다 호출
{
	Super::Tick(DeltaTime); // 부모 클래스의 Tick도 실행

	if (Counter < MaxCount)
	{
		
		//move(20 * DeltaTime, 0, 20 * DeltaTime); //X방향 20, Y방향 0, Z방향 20 으로 프레임마다 이동
		move(RandomNumber1 * DeltaTime, RandomNumber2 * DeltaTime, RandomNumber3 * DeltaTime);

		//turn(40 * DeltaTime, 0, 40 * DeltaTime); //Pitch(위아래) 40, Yaw(좌우) 0, Rall(기울기) 40 으로 프레임마다 회전
		turn(RandomNumber1 * DeltaTime, RandomNumber2 * DeltaTime, RandomNumber3 * DeltaTime);

	}

}

void AMyActor::move(float deltaX, float deltaY, float deltaZ) //액터 이동
{
	FVector NewLocation = GetActorLocation(); //현재 액터 위치 가져옴

	NewLocation.X += deltaX; //기존 위치에 이동할 거리 더해서 새로운 위치 구함
	NewLocation.Y += deltaY;
	NewLocation.Z += deltaZ;

	SetActorLocation(NewLocation); //새로 구한 위치 액터에 적용
}

void AMyActor::turn(float deltaPitch, float deltaYaw, float deltaRoll) //액터 회전
{
	FRotator DeltaRotation(deltaPitch, deltaYaw, deltaRoll);

	AddActorWorldRotation(DeltaRotation);
}

void AMyActor::randomNumber()
{
	for (int i = 0; i < 10; i++)
	{
		RandomNumber1 = FMath::RandRange(MinValue, MaxValue);
		RandomNumber2 = FMath::RandRange(MinValue, MaxValue);
		RandomNumber3 = FMath::RandRange(MinValue, MaxValue);
	
	}

	Counter++;

}

void AMyActor::printNumber()
{
	if (Counter >= MaxCount)
	{
		return;
	}

	GEngine->AddOnScreenDebugMessage
	(
		-1,
		30.0f,
		FColor::Green,
		FString::Printf(TEXT("positionX = %d, positionY = %d, positionZ = %d, Count = %d"), RandomNumber1, RandomNumber2, RandomNumber3, Counter)

	);


}