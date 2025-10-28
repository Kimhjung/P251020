#include "Actor.h"
#include "Engine.h"

#include <iostream>
#include <windows.h>
#include "Component.h"

using namespace std;

AActor::AActor() :
	Location(0, 0)
{
	
}

AActor::~AActor()
{
	for (auto Components : Components)
	{
		delete Components;
	}
}

void AActor::Tick()
{
	
}

void AActor::Render()
{
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

void AActor::AddComponent(UComponent* InComponent)
{
	Components.push_back(InComponent);
}