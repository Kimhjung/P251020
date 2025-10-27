#include <iostream>
#include <windows.h>

#include "Actor.h"

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
}

bool AActor::CheckColision(const AActor* Other)
{
	if (Other->bIsOverlap)
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