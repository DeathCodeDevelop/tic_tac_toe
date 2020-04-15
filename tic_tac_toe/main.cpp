#include <iostream>
#include "menu.h"
#include "draw.h"
#include "logic.h"
#include "input.h"
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

	if (!menu.playWithComputer) 
	{
		bool gameWork = true;
		bool crossTurn = true;
		Cordinats cordinats;

		do
		{
			Draw(map);
			
			cordinats = Input(map);

			if (crossTurn)
			{
				map[cordinats.y][cordinats.x] = 'x';
				
			}
			else
			{
				map[cordinats.y][cordinats.x] = 'o';
				
			}

			gameWork = Logic(map, crossTurn);

			crossTurn = !crossTurn;
			
		} while (gameWork);

		Draw(map);
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
