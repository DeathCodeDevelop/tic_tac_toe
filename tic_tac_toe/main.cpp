#include <iostream>
#include "menu.h"
using namespace std;

char** CreateMap(int rows, int cols);

int main() 
{
	Menu menu = ShowMenu();

	cout << "play with computer = > " << menu.playWithComputer << endl;
	cout << "difficalty = > " << menu.difficulty << endl;
	cout << "you first = > " << menu.youFirstPlayer << endl;

	int rows = 3, cols = 3;
	char** map = CreateMap(rows, cols);

	if (!menu.playWithComputer) 
	{
		
	}
	else if (menu.playWithComputer) 
	{
		
	}

	return 0;
}

char** CreateMap(int rows, int cols)
{
	char** map = new char* [rows];

	for (int i = 0; i < rows; i++)
	{
		map[i] = new char[cols];
	}

	return map;
}
