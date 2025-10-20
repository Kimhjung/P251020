#pragma once
#include <vector>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	// 모든 액터 가져오기
	std::vector<AActor*> GetAllActors() const;

	AActor* SpawnActor(AActor* NewActor);

	virtual void Tick();
	virtual void Render();

protected:
	std::vector<AActor*> Actors;
};

