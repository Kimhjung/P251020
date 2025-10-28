#pragma once

#include <vector>
#include "Vector.h"
#include "SDL3/SDL.h"
#include "Component.h"

class UComponent;

class AActor
{
public:
	AActor();
	virtual ~AActor();

	//virtual function table => vftbl
	virtual void Tick();	// virtual: �ڽ��� �������Ҽ��� �־�. List ã�ƺ�
	virtual void Render();

	//inline: �޸𸮸� ���� ����
	//__forceinline: 
	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	void SetActorLocation(FVector2D Value)
	{
		// ���� ������(�ɼ���, �ȵɼ���)
		//Location = Value;

		Location.X = Value.X;
		Location.Y = Value.Y;

	}
	//virtual void SimulatePhysics();
	bool CheckCollision(const AActor* Other);

	virtual void ActorBeginOverlap();
	virtual void Hit();

	void AddComponent(UComponent* InComponent);

	std::vector<class UComponent*> Components;

protected:
	FVector2D Location;

public:
	bool bIsCollision = false;
	bool bIsOverlap = true;
};

