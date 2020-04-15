#include <iostream>
#include "menu.h"
#include "draw.h"
#include "logic.h"
using namespace std;

char** CreatenewMap(int rows, int cols);

int main() 
{
	Menu menu = ShowMenu();

	cout << "play with computer = > " << menu.playWithComputer << endl;
	cout << "difficalty = > " << menu.difficulty << endl;
	cout << "you first = > " << menu.youFirstPlayer << endl;

	int rows = 3, cols = 3;
	char** map = CreatenewMap(rows, cols);

	map[0][0] = 'x';
	map[1][1] = 'x';
	map[2][2] = 'x';

	if (!menu.playWithComputer) 
	{
		
	}
	else if (menu.playWithComputer) 
	{
		
	}

	return 0;
}

char** CreatenewMap(int rows, int cols)
{
	char** newMap = new char* [rows];

	for (int i = 0; i < rows; i++)
	{
		newMap[i] = new char[cols];
	}

	return newMap;
}
