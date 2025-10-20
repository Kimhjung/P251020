#include "World.h"
#include "Actor.h"

UWorld::UWorld()
{

}

UWorld::~UWorld()
{

}

std::vector<AActor*> UWorld::GetAllActors() const
{
	return Actors;
}

AActor* UWorld::SpawnActor(AActor* NewActor)
{
	return nullptr;
}

void UWorld::Tick()
{
	for(auto Actor:Actors)
	{
		Actor->Tick();
	}
}
void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}