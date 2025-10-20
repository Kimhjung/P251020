#include <iostream>
#include "Actor.h"
#include "Player.h"

using namespace std;

int main()
{
	APlayer* MyPlayer = new APlayer();

	MyPlayer->Tick();

	delete MyPlayer;

	return 0;
}