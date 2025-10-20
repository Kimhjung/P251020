#pragma once

#include "Vector.h"

class AActor
{
public:
	AActor();
	virtual ~AActor();

	//virtual function table => vftbl
	virtual void Tick();	// virtual: 자식이 재정의할수도 있어. List 찾아봐

	//inline: 메모리를 갖다 붙임
	//__forceinline: 
	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	void SetActorLocation(FVector2D Value)
	{
		// 복사 생성자(될수도, 안될수도)
		//Location = Value;

		Location.X = Value.X;
		Location.Y = Value.Y;

	}

private:
	FVector2D Location;
};

