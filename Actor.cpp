#include "Actor.h"
#include <iostream>

using namespace std;

AActor::AActor()
{
	cout << "Actor ������" << endl;
}

AActor::~AActor()
{
	cout << "Actor �Ҹ���" << endl;
}

void AActor::Tick()
{
	cout << "Actor Tick" << endl;
}
