#include <iostream>
#include "menu.h"
#include "draw.h"
#include "logic.h"
#include "input.h"
#include "low.h"
#include "medium.h"
#include "high.h"
#include "map.h"
using namespace std;

Cordinats EnemyTurn(int difficulty, char** map, bool youFirstPlayer);

int main()
{
	Menu menu = ShowMenu();

	if (menu.exitTrue)
		return 0;
	
	bool gameWork = true, crossTurn = true, noBodyWon = false;
	Cursor cursor = { 0, 0 };
	Cordinats cordinats;
	size_t size = 3;
	char** map = CreateNewMap(size);

	if (!menu.youFirstPlayer && menu.playWithComputer)
	{
		cordinats = EnemyTurn(menu.difficulty, map, menu.youFirstPlayer);
		map[cordinats.y][cordinats.x] = 'x';
		crossTurn = !crossTurn;
	}

	do
	{
		Draw(map, cursor, crossTurn, menu.colorData);
		Input(map, crossTurn, menu.colorData);

		if (menu.playWithComputer)
		{
			gameWork = Logic(map, crossTurn);

			if (Logic(map, crossTurn) == NOBODY_WON)
			{
				noBodyWon = true;
				break;
			}

			crossTurn = !crossTurn;

			cordinats = EnemyTurn(menu.difficulty, map, menu.youFirstPlayer);

			if (menu.youFirstPlayer)
				map[cordinats.y][cordinats.x] = 'o';
			else
				map[cordinats.y][cordinats.x] = 'x';
		}

		gameWork = Logic(map, crossTurn);

		if (Logic(map, crossTurn) == NOBODY_WON)
		{
			noBodyWon = true;
			break;
		}

		crossTurn = !crossTurn;
	} while (gameWork);

	cursor = { -1, -1 };
	Draw(map, cursor, crossTurn, menu.colorData);

	if (noBodyWon)
		cout << " nobody won!!!\n";
	else if (!crossTurn)
		cout << " x win!!!\n";
	else
		cout << " o win!!!\n";

	return 0;
}

Cordinats EnemyTurn(int difficulty, char** map, bool youFirstPlayer)
{
	switch (difficulty)
	{
	case 0:
		return Low(map);
		break;
	case 1:
		return Medium(map, youFirstPlayer);
		break;
	case 2:
		return High(map, youFirstPlayer);
		break;
	}

	return { 0, 0 };
}