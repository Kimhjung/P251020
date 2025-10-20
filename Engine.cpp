#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>

#include "Engine.h"

#include "World.h"
#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Goal.h"
#include "Monster.h"

using namespace std;

//FEngine* GEngine = nullptr;

FEngine* FEngine::Instance = nullptr;

FEngine::FEngine() : 
	World(nullptr)
{
	
}

FEngine::~FEngine()
{

}

void FEngine::Init()
{
	int* ZOrder[1024] = { 0, };

	World = new UWorld();

	std::ifstream Map("level01.map");

	if (Map.is_open())
	{
		cout << "맵 로드" << endl;

		char Buffer[1024] = { 0 };
		int Y = 0;

		while (Map.getline(Buffer, 80))
		{

			std::string Line = Buffer;
			for (int X = 0; X < Line.size(); ++X)
			{
				if (Line[X] == '*')
				{
					AActor* Wall = new AWall();
					Wall->SetActorLocation(FVector2D(X, Y));
					Wall->SetShape(Line[X]);
					World->SpawnActor(Wall);
					ZOrder[X] = &Wall->ZOrder;
				}
				else if (Line[X] == 'P')
				{
					AActor* Player = new APlayer();
					Player->SetActorLocation(FVector2D(X, Y));
					Player->SetShape(Line[X]);
					World->SpawnActor(Player);
					ZOrder[X] = &Player->ZOrder;
				}
				else if (Line[X] == 'M')
				{
					AActor* Monster = new AMonster();
					Monster->SetActorLocation(FVector2D(X, Y));
					Monster->SetShape(Line[X]);
					World->SpawnActor(Monster);
					ZOrder[X] = &Monster->ZOrder;
				}
				else if (Line[X] == 'G')
				{
					AActor* Goal = new AGoal();
					Goal->SetActorLocation(FVector2D(X, Y));
					Goal->SetShape(Line[X]);
					World->SpawnActor(Goal);
					ZOrder[X] = &Goal->ZOrder;
				}
				else if (Line[X] == ' ')
				{
					AActor* Floor = new AFloor();
					Floor->SetActorLocation(FVector2D(X, Y));
					Floor->SetShape(Line[X]);
					World->SpawnActor(Floor);
					ZOrder[X] = &Floor->ZOrder;
				}
			}
			Y++;

			//문제: ZOrder 값에 따라 숫자가 높은 애가 맨 위에 보이게 해라
			/*
			* 내 해석: ZOrder가 0인 것부터 그려라
			* 각 액터의 ZOrder를 어떻게 비교할 수 있을까
			* 배열로 받아? -> 넣을 액터를 pointer로 지정해서 통으로 넣어주면 될 것 같은데...
			*/
			// printf("%d",ZOrder[0]);	//주소값 출력됨
			// printf("%d",*ZOrder[0]);	//값 출력됨
		}
	}
	else
	{
		cout << "맵 로드 안됨";
	}

	Map.close();

}


void FEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void FEngine::Term()
{

}

void FEngine::Input()
{
	KeyCode = _getch();
}

void FEngine::Tick()
{
	GetWorld()->Tick();
}

void FEngine::Render()
{
	system("cls");

	GetWorld()->Render();
}