#pragma once
#include <vector>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	// 모든 액터 가져오기
	void GetAllActors(std::vector<AActor*>& OutActors) const;

	AActor* SpawnActor(AActor* NewActor);

	virtual void Tick();
	virtual void Render();

	void SortActor();

protected:
	std::vector<AActor*> Actors;
};

