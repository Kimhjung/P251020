#include "Engine.h"
#include "Player.h"
#include <iostream>

using namespace std;

APlayer::APlayer()
{
	ZOrder = 3;
}

APlayer::~APlayer()
{
	
}

void APlayer::Tick()
{
	//Unreal: super::AActor::Tick();
	//C++: __super::Tick();
	//�� �ܰ� ��(�θ�)�� �Լ� ȣ��

	//�θ�Ŭ���� �Լ� ȣ��
	int KeyCode = GEngine->GetKeyCode();

	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	if (KeyCode == 's')
	{
		Location.Y++;
	}
	if (KeyCode == 'a')
	{
		Location.X--;
	}
	if (KeyCode == 'd')
	{
		Location.X++;
	}
}
