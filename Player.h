#pragma once

#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	~APlayer();

	virtual void Tick() override;	//override: 이건 부모껀데(상속받았는데) 내가 재정의함 / 내 자식도 이거 재정의할수도 있음

	//overloading: 같은 클래스에서 함수 이름은 같으나, 인자가 다른 함수(C++)
	//들어온 값에 따라 실행되는 내용이 달라짐
	void Jump(void)
	{

	}

	void Jump(int a)
	{

	}

	void Jump(float a)
	{

	}
};

