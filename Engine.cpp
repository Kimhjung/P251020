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
		cout << "�� �ε�" << endl;

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

			//����: ZOrder ���� ���� ���ڰ� ���� �ְ� �� ���� ���̰� �ض�
			/*
			* �� �ؼ�: ZOrder�� 0�� �ͺ��� �׷���
			* �� ������ ZOrder�� ��� ���� �� ������
			* �迭�� �޾�? -> ���� ���͸� pointer�� �����ؼ� ������ �־��ָ� �� �� ������...
			*/
			// printf("%d",ZOrder[0]);	//�ּҰ� ��µ�
			// printf("%d",*ZOrder[0]);	//�� ��µ�
		}
	}
	else
	{
		cout << "�� �ε� �ȵ�";
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