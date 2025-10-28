#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<algorithm>

#include "Engine.h"

#include "World.h"
#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Goal.h"
#include "Monster.h"
#include "GameMode.h"
#include "Timer.h"

using namespace std;

//FEngine* GEngine = nullptr;

FEngine* FEngine::Instance = nullptr;

FEngine::FEngine() : World(nullptr)
{
	MyRenderer = nullptr;
	MyWindow = nullptr;
	Timer = new UTimer();
	MyEvent = SDL_Event();
}

FEngine::~FEngine()
{
	if (World)
	{
		delete World;
	}
	if (Timer)
	{
		delete Timer;
	}
}

void FEngine::Init()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	MyWindow = SDL_CreateWindow("Game", 640, 480, SDL_WINDOW_OPENGL);

	MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	OpenLevel();
	
}

void FEngine::OpenLevel()
{
	srand((unsigned int)time(nullptr));

	World = new UWorld();

	std::ifstream Map("level01.map");

	if (Map.is_open())
	{
		cout << "맵 로드" << endl;

		char Buffer[1024] = { 0 };
		int Y = 0;

		while (Map.getline(Buffer, 80))
		{
			string Line = Buffer;
			for (int X = 0; X < Line.size(); ++X)
			{
				if (Line[X] == '*')
				{
					AActor* Wall = new AWall();
					Wall->SetActorLocation(FVector2D(X, Y));
					Wall->SetShape(Line[X]);
					World->SpawnActor(Wall);
				}
				else if (Line[X] == 'P')
				{
					AActor* Player = new APlayer();
					Player->SetActorLocation(FVector2D(X, Y));
					Player->SetShape(Line[X]);
					World->SpawnActor(Player);
				}
				else if (Line[X] == 'M')
				{
					AActor* Monster = new AMonster();
					Monster->SetActorLocation(FVector2D(X, Y));
					Monster->SetShape(Line[X]);
					World->SpawnActor(Monster);
				}
				else if (Line[X] == 'G')
				{
					AActor* Goal = new AGoal();
					Goal->SetActorLocation(FVector2D(X, Y));
					Goal->SetShape(Line[X]);
					World->SpawnActor(Goal);
				}
				else if (Line[X] == ' ')
				{
					AActor* Floor = new AFloor();
					Floor->SetActorLocation(FVector2D(X, Y));
					Floor->SetShape(Line[X]);
					World->SpawnActor(Floor);
				}
			}
			Y++;

			//문제: ZOrder 값에 따라 숫자가 높은 애가 맨 위에 보이게 해라
			World->SortActor();
		}
	}
	else
	{
		cout << "맵 로드 안됨";
	}

	Map.close();

	World->SortActor();
}


void FEngine::Run()
{
	while (bIsRunning)
	{
		Timer->Tick();
		//첫프레임은 0으로 초기화
		float StartTime = SDL_GetTicks64();
		DeltaSeconds = SDL_GetTicks64() - StartTime;
		//Input();
		SDL_PollEvent(&MyEvent);
		Tick();
		Render();
	}
}

void FEngine::Term()
{
	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();
}

void FEngine::Input()
{
	if (_kbhit())
	{
		KeyCode = _getch();
	}
}

void FEngine::Tick()
{
	GetWorld()->Tick();
}

void FEngine::Render()
{
	//system("cls");
	SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
	SDL_RenderClear(MyRenderer);

	GetWorld()->Render();

	SDL_RenderPresent(MyRenderer);
}

double FEngine::GetWorldDeltaSeconds() const
{
	return Timer->DeltaSeconds;
}
