#include "PaperFilpbookComponent.h"
#include <iostream>
#include <Windows.h>
#include "Vector.h"
#include "Actor.h"
#include "Engine.h"

UPaperFilpbookComponent::UPaperFilpbookComponent()
{
}

UPaperFilpbookComponent::~UPaperFilpbookComponent()
{
}

void UPaperFilpbookComponent::Tick()
{
}

void UPaperFilpbookComponent::Render()
{
	/*COORD Position;
	Position.X = GetOwner()->GetActorLocation().X;
	Position.Y = GetOwner()->GetActorLocation().Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);

	std::cout << Shape;*/

	SDL_SetRenderDrawColor(GEngine->MyRenderer, Color.r, Color.g, Color.b, Color.a);
	//SDL_RenderDrawPoint(GEngine->MyRenderer, Position.X, Position.Y);

	int SizeX = 30;
	int SizeY = 30;

	SDL_FRect DrawRect =
	{
		(float)(GetOwner()->GetActorLocation().X * SizeX),
		(float)(GetOwner()->GetActorLocation().Y * SizeY),
		(float)SizeX,
		(float)SizeY
	};
	SDL_RenderFillRect(GEngine->MyRenderer, &DrawRect);
}
