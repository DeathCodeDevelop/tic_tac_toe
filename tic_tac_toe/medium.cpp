#include "medium.h"

Cordinats Medium(char** map, bool playerFirst)
{
	/*
		this function determines where to place the symbol to win or not to win the opponent
	*/

	char symbol;
	char enemySymbol;
	const size_t TURN_QUANTITYS = 3 * 3;
	size_t remainingTurns = TURN_QUANTITYS;
	Cordinats cordinats;

	if (playerFirst)
	{
		symbol = 'o';
		enemySymbol = 'x';
	}
	else
	{
		symbol = 'x';
		enemySymbol = 'o';
	}

	for (size_t i = 0; i < 3; i++) // determining the number of moves left
		for (size_t j = 0; j < 3; j++)
			if (map[i][j] == 'x' || map[i][j] == 'o')
				remainingTurns--;

	if (MaybeSomeoneWon(map, cordinats, symbol, remainingTurns, !playerFirst))			// check for computer
		return cordinats;
	else if (MaybeSomeoneWon(map, cordinats, enemySymbol, remainingTurns, playerFirst)) // check for player
		return cordinats;
	else																				// else put on random
		cordinats = Low(map);

	return cordinats;
}

bool MaybeSomeoneWon(char** map, Cordinats& cordinats, char symbol, size_t remainingTurns, bool playerFirst)
{
	/*
		this feature checks if someone can win if they make one turn
	*/

	size_t size = 3;
	size_t turn = 0;
	char** newMap = CreateNewMap(size); // in order to secure the main array
	char** turnMap = CreateNewMap(size); // in order not to hit at one point


	CopyMap(map, turnMap, size); // copy main map to turn map

	do
	{
		CopyMap(map, newMap, size); // copy main map to new check map
		cordinats = Low(turnMap);
		newMap[cordinats.y][cordinats.x] = symbol; // write to the array for check
		turnMap[cordinats.y][cordinats.x] = symbol; // write to the array of moves

		if (Logic(newMap, playerFirst) == WIN) // check win
		{
			DeleteMap(turnMap, size);
			DeleteMap(newMap, size);
			return true;
		}

		turn++;
	} while (turn < remainingTurns);

	DeleteMap(newMap, size);
	DeleteMap(turnMap, size);
	return false;
}