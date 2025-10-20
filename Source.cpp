#include <iostream>
#include <vector>	//STL ã�ƺ���
#include <fstream>
#include <string>

#include "Engine.h"

using namespace std;

class Singleton
{
protected:
	Singleton()
	{

	}
	
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton;
		}
		return Instance;
	}

protected:
	static Singleton* Instance;
	
};

Singleton* Singleton::Instance = nullptr;

int main(int argc, char* argv[])
{
	Singleton* S1 = Singleton::GetInstance();

	FEngine* MyEngine = new FEngine();

	GEngine = MyEngine;

	MyEngine->Init();
	MyEngine->Run();
	MyEngine->Term();

	delete MyEngine;
	MyEngine = nullptr;

	return 0;
}