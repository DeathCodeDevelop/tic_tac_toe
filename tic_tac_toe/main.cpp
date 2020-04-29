#include <iostream>
#include "menu.h"
#include "draw.h"
#include "logic.h"
#include "input.h"
#include "low.h"
#include "medium.h"
#include "map.h"
using namespace std;

char** CreatenewMap(int rows, int cols);

int main()
{
	Menu menu = ShowMenu();

	//cout << "play with computer = > " << menu.playWithComputer << endl;
	//cout << "difficalty = > " << menu.difficulty << endl;
	//cout << "you first = > " << menu.youFirstPlayer << endl;

	int rows = 3, cols = 3;
	char** map = CreatenewMap(rows, cols);
	int count = 0;

	if (menu.exitTrue)
		return 0;

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
			cout << " nobody won!!!\n";
		else if (!crossTurn)
			cout << " x win!!!\n";
		else
			cout << " o win!!!\n";
	}
	else if (menu.playWithComputer)
	{
		bool gameWork = true;
		bool crossTurn = true;
		Cursor cursor = { -1,-1 };
		bool noBodyWon = false;
		Cordinats cordinats;

		do
		{
			count++;

			Draw(map, cursor, crossTurn);

			if (menu.youFirstPlayer)
			{
				if (crossTurn)
				{
					Input(map, true);
				}
				else
				{
					switch (menu.difficulty)
					{
					case 0:
						cordinats = Low(map);
						break;
					case 1:
						cordinats = Medium(map, true);
						break;
					case 2:
						break;
					}
					map[cordinats.y][cordinats.x] = 'o';
				}
			}
			else
			{
				if (crossTurn)
				{
					switch (menu.difficulty)
					{
					case 0:
						cordinats = Low(map);
						break;
					case 1:
						cordinats = Medium(map, false);
						break;
					case 2:
						break;
					}
					map[cordinats.y][cordinats.x] = 'x';
				}
				else
				{
					Input(map, false);
				}
			}

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
			cout << " nobody won!!!\n";
		else if (!crossTurn)
			cout << " x win!!!\n";
		else
			cout << " o win!!!\n";
	}

	return 0;
}