#include "Engine.h"
#include "Player.h"
#include <iostream>

using namespace std;

APlayer::APlayer()
{
	
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
}
