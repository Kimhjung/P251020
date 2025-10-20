#include <iostream>
#include <vector>	//STL Ã£¾Æº¸±â
#include <fstream>
#include <string>

#include "Engine.h"

using namespace std;

int main()
{

	ifstream Map("Level01.map");

	cout << "¸Ê ·Îµå" << endl;

	if (Map.is_open())
	{
		char Buffer[1024] = { 0, };
		int Y = 0;
		/*
		Map.getline(Buffer, 255);
		cout << Buffer << endl;
		*/
		while (Map.getline(Buffer, 80))
		{
			Y++;
			string Line = Buffer;
			for(int X = 0; X < Line.size(); ++X)
			{
				if (Line[X] == '\0')
				{
					continue;
				}
				cout << Line[X];
			}
			cout << endl;
			Y++;
		}
	}
	else
	{
		cout << "¸Ê ·Îµå ¾ÈµÊ";
	}
	Map.close();

	return 0;
}