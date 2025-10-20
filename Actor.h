#pragma once

#include "Vector.h"

class AActor
{
public:
	AActor();
	virtual ~AActor();

	//virtual function table => vftbl
	virtual void Tick();	// virtual: �ڽ��� �������Ҽ��� �־�. List ã�ƺ�

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

private:
	FVector2D Location;
};

