#include "Engine.h"
#include "Player.h"
#include "World.h"
#include <iostream>
#include "SDL3/SDL.h"
#include "PaperFilpbookComponent.h"

using namespace std;

APlayer::APlayer()
{
	bIsCollision = true;
	bIsOverlap = true;

	UPaperFilpbookComponent* Paper = new UPaperFilpbookComponent();

	Paper->SetShape('P');
	Paper->SetOwner(this);
	Paper->ZOrder = 3;
	Paper->Color = { 0, 0, 255, 0 };
	AddComponent(Paper);
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

	if (KeyCode == SDLK_w || KeyCode == SDLK_UP)
	{
		Location.Y--;
	}
	if (KeyCode == SDLK_s || KeyCode == SDLK_DOWN)
	{
		Location.Y++;
	}
	if (KeyCode == SDLK_a || KeyCode == SDLK_LEFT)
	{
		Location.X--;
	}
	if (KeyCode == SDLK_d || KeyCode == SDLK_RIGHT)
	{
		Location.X++;
	}

	if (KeyCode == SDLK_ESCAPE)
	{
		exit(-1);
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
