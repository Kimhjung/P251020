#include "Player.h"
#include <iostream>

using namespace std;

APlayer::APlayer()
{
	cout << "player ������" << endl;
}

APlayer::~APlayer()
{
	cout << "player �Ҹ���" << endl;
}

void APlayer::Tick()
{
	//Unreal: super::AActor::Tick();
	//C++: __super::Tick();
	//�� �ܰ� ��(�θ�)�� �Լ� ȣ��

	//�θ�Ŭ���� �Լ� ȣ��
	AActor::Tick();

	cout << "player Tick" << endl;
}
