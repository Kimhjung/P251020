#include "Engine.h"
#include "Player.h"
#include "World.h"
#include <iostream>

using namespace std;

APlayer::APlayer()
{
	ZOrder = 3;
	bIsColision = true;
	bIsOverlap = true;
}

APlayer::~APlayer()
{
	
}

void APlayer::Tick()
{
	//Unreal: super::AActor::Tick();
	//C++: __super::Tick();
	//한 단계 위(부모)의 함수 호출

	//부모클래스 함수 호출
	int KeyCode = GEngine->GetKeyCode();

	FVector2D SaveLocation;
	SaveLocation = Location;

	if (KeyCode == 'w' || KeyCode == 'W')
	{
		Location.Y--;
	}
	if (KeyCode == 's' || KeyCode == 'S')
	{
		Location.Y++;
	}
	if (KeyCode == 'a' || KeyCode == 'A')
	{
		Location.X--;
	}
	if (KeyCode == 'd' || KeyCode == 'D')
	{
		Location.X++;
	}

	vector<AActor*> AllActors;

	GEngine->GetWorld()->GetAllActors(AllActors);

	bool bFlag = false;

	for (auto OtherActor : AllActors)
	{
		if (CheckColision(OtherActor))
		{
			bFlag = true;
			break;
		}
	}

	if (bFlag)
	{
		Location = SaveLocation;
	}
}
