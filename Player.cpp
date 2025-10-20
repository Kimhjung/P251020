#include "Player.h"
#include <iostream>

using namespace std;

APlayer::APlayer()
{
	cout << "player 생성자" << endl;
}

APlayer::~APlayer()
{
	cout << "player 소멸자" << endl;
}

void APlayer::Tick()
{
	//Unreal: super::AActor::Tick();
	//C++: __super::Tick();
	//한 단계 위(부모)의 함수 호출

	//부모클래스 함수 호출
	AActor::Tick();

	cout << "player Tick" << endl;
}
