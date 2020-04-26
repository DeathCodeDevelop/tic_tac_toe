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
	int count = 0;

	if (!menu.playWithComputer) 
	{
		bool gameWork = true;
		bool crossTurn = true;
		Cursor cursor = { -1,-1 };
		bool noBodyWon = false;
		
		do
		{
			count++;

			Draw(map, cursor, crossTurn);
			Input(map, crossTurn);
			gameWork = Logic(map, crossTurn);

			if (count == 9 && Logic(map, crossTurn))
			{
				noBodyWon = true;
				break;
			}

			crossTurn = !crossTurn;
		} while (gameWork);

		Draw(map, cursor, crossTurn);

		if (noBodyWon) 
			cout << "nobody won!!!\n";
		else if (!crossTurn)
			cout << " x win!!!\n";
		else
			cout << " o win!!!\n";
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
