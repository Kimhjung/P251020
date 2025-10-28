#include "World.h"
#include "Actor.h"
#include "SceneComponent.h"
#include "PaperFilpbookComponent.h"
#include <algorithm>

UWorld::UWorld()
{

}

UWorld::~UWorld()
{

}

void UWorld::GetAllActors(std::vector<AActor*>& OutActors) const
{
	OutActors = Actors;
}

AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}

void UWorld::Tick()
{
	for(auto Actor:Actors)
	{
		//runtime시에 결정됨
		Actor->Tick();
	}
}
void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		for(auto Component : Actor->Components)
		{
			USceneComponent* Scene = dynamic_cast<USceneComponent*>(Component);
			if (Scene)
			{
				Scene->Render();
			}
		}
	}
}

// [][][][][][][][][][]
void UWorld::SortActor()
{
	//람다 함수
	std::sort(Actors.begin(), Actors.end(), [](const AActor* A, const AActor* B) {
		UPaperFilpbookComponent* Scene1 = nullptr;
		for (auto Component : A->Components)
		{
			Scene1 = dynamic_cast<UPaperFilpbookComponent*>(Component);
			if (Scene1)
			{
				break;
			}
			
		}
		UPaperFilpbookComponent* Scene2 = nullptr;
		for (auto Component : B->Components)
		{
			Scene2 = dynamic_cast<UPaperFilpbookComponent*>(Component);
			if (Scene2)
			{
				break;
			}
		}

		if (!Scene1 || !Scene2)
		{
			return false;
		}

		return (Scene1->GetZOrder() < Scene2->GetZOrder());
	});
	
	std::sort(Actors.begin(), Actors.end());
}