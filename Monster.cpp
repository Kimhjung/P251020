#include "Monster.h"
#include "Engine.h"
#include "Actor.h"
#include "World.h"
#include <vector>

using namespace std;

AMonster::AMonster()
{
	ZOrder = 3;
	bIsCollision = true;
	bIsOverlap = true;
	Color = { 255, 0, 0, 0 };
}

AMonster::~AMonster()
{

}

void AMonster::Tick()
{
	int KeyCode = rand() % 4;

	FVector2D SaveLocation;
	SaveLocation = Location;

	if (KeyCode == 0)
	{
		Location.Y--;
	}
	if (KeyCode == 1)
	{
		Location.Y++;
	}
	if (KeyCode == 2)
	{
		Location.X--;
	}
	if (KeyCode == 3)
	{
		Location.X++;
	}

	vector<AActor*> AllActors;

	GEngine->GetWorld()->GetAllActors(AllActors);

	bool bFlag = false;

	for (auto OtherActor : AllActors)
	{
		if (CheckCollision(OtherActor) && this != OtherActor)
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
