#include "Engine.h"
#include "Player.h"
#include "World.h"
#include <iostream>

using namespace std;

APlayer::APlayer()
{
	ZOrder = 3;
	bIsCollision = true;
	bIsOverlap = true;
	Color = { 0, 0, 255, 0 };
}

APlayer::~APlayer()
{
	
}

void APlayer::Tick()
{
	//Unreal: super::AActor::Tick();
	//C++: __super::Tick();
	//�� �ܰ� ��(�θ�)�� �Լ� ȣ��

	//�θ�Ŭ���� �Լ� ȣ��
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
		if (CheckCollision(OtherActor))
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
