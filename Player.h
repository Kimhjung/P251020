#pragma once

#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	~APlayer();

	virtual void Tick() override;	//override: �̰� �θ𲫵�(��ӹ޾Ҵµ�) ���� �������� / �� �ڽĵ� �̰� �������Ҽ��� ����

	//overloading: ���� Ŭ�������� �Լ� �̸��� ������, ���ڰ� �ٸ� �Լ�(C++)
	//���� ���� ���� ����Ǵ� ������ �޶���
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

