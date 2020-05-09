#include <iostream>
#include "menu.h"
#include "draw.h"
#include "logic.h"
#include "input.h"
#include "low.h"
#include "medium.h"
#include "map.h"
using namespace std;

char** CreateNewMap(int rows, int cols);

int main()
{
	Menu menu = ShowMenu();
	
	//cout << menu.colorData[0] << endl;
	//cout << menu.colorData[1] << endl;
	//cout << menu.colorData[2] << endl;
	//cout << menu.colorData[3] << endl;

	//return 0;

	//cout << "play with computer = > " << menu.playWithComputer << endl;
	//cout << "difficalty = > " << menu.difficulty << endl;
	//cout << "you first = > " << menu.youFirstPlayer << endl;

	size_t size = 3;
	char** map = CreateNewMap(size);

	if (menu.exitTrue)
		return 0;

	if (!menu.playWithComputer)
	{
		bool gameWork = true;
		bool crossTurn = true;
		Cursor cursor = { 0, 0 };
		bool noBodyWon = false;

		do
		{
			Draw(map, cursor, crossTurn, menu.colorData);
			Input(map, crossTurn, menu.colorData);
			gameWork = Logic(map, crossTurn);

			if (Logic(map, crossTurn) == NOBODY_WON)
			{
				noBodyWon = true;
				break;
			}

			crossTurn = !crossTurn;
		} while (gameWork);

		Draw(map, cursor, crossTurn, menu.colorData);

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
		Cursor cursor = { 0,0 };
		bool noBodyWon = false;
		Cordinats cordinats;

		do
		{
			Draw(map, cursor, crossTurn, menu.colorData);

			if (menu.youFirstPlayer)
			{
				if (crossTurn)
				{
					Input(map, true, menu.colorData);
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
					Input(map, false, menu.colorData);
				}
			}

			gameWork = Logic(map, crossTurn);

			if (Logic(map, crossTurn) == NOBODY_WON)
			{
				noBodyWon = true;
				break;
			}

			crossTurn = !crossTurn;
		} while (gameWork);
	}

	/*Draw(map, cursor, crossTurn, menu.colorData);

	if (noBodyWon)
		cout << " nobody won!!!\n";
	else if (!crossTurn)
		cout << " x win!!!\n";
	else
		cout << " o win!!!\n";*/

	return 0;
}