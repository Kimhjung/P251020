#pragma once

#include "Vector.h"

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

	__forceinline char GetShape()
	{
		return Shape;
	}

	void SetShape(char Value)
	{
		Shape = Value;
	}
	__forceinline int GetZOrder() const
	{
		return ZOrder;
	}

protected:
	FVector2D Location;
	char Shape;
	int ZOrder;
};

