#include "Monster.h"
#include <vector>
#include "World.h"

using namespace std;

AMonster::AMonster()
{
	ZOrder = 3;
}

AMonster::~AMonster()
{

}

void AMonster::Tick()
{
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
		if (CheckColision(OtherActor) && this != OtherActor)
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
