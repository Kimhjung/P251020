#include <iostream>
#include <vector>	//STL ã�ƺ���

#include "Engine.h"


using namespace std;

int main()
{
	FEngine* MyEngine = new FEngine();
	
	MyEngine->Init();
	MyEngine->Run();
	MyEngine->Term();

	delete MyEngine;
	MyEngine = nullptr;

	return 0;
}