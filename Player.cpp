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
	//한 단계 위(부모)의 함수 호출

	//부모클래스 함수 호출
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
