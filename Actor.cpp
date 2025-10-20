#include "Actor.h"
#include <iostream>

using namespace std;

AActor::AActor()
{
	cout << "Actor 持失切" << endl;
}

AActor::~AActor()
{
	cout << "Actor 社瑚切" << endl;
}

void AActor::Tick()
{
	cout << "Actor Tick" << endl;
}
