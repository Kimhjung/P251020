#include "Actor.h"
#include "Engine.h"

#include <iostream>
#include <windows.h>

using namespace std;

AActor::AActor() :
	Shape(' '), Location(0, 0)
{
	
}

AActor::~AActor()
{
	
}

void AActor::Tick()
{
	
}

void AActor::Render()
{
	COORD Position;
	Position.X = Location.X;
	Position.Y = Location.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
	
	std::cout << Shape;

	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	//SDL_RenderDrawPoint(GEngine->MyRenderer, Position.X, Position.Y);

	int SizeX = 30;
	int SizeY = 30;

	SDL_FRect DrawRect =
	{
		(float)(Location.X * SizeX),
		(float)(Location.Y * SizeY),
		(float)SizeX,
		(float)SizeY
	};
	SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
}

bool AActor::CheckCollision(const AActor* Other)
{
	if (Other->bIsOverlap)
	{
		return false;
	}

	if (this != Other && Other->bIsCollision && bIsCollision &&
		this->Location == Other->Location) //영역 계산
	{
		return true;
	}

	return false;
}

void AActor::ActorBeginOverlap()
{
}

void AActor::Hit()
{
}