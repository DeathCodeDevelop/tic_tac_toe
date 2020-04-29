#include "medium.h"

Cordinats Medium(char** map, bool playerFirst)
{
	char symbol;
	char mySymbol;

	if (playerFirst)
	{
		symbol = 'x';
		mySymbol = 'o';
	}
	else
	{
		symbol = 'o';
		mySymbol = 'x';
	}

	int size = 3;
	char** newMap = CreatenewMap(size, size);

	Cordinats cordinats;

	CopyMap(map, newMap, size);

	do
	{
		cordinats = Low(newMap);
		newMap[cordinats.y][cordinats.x] = symbol;

		if (Logic(newMap, playerFirst) == NOBODY_WON)
			break;

	} while (Logic(newMap, playerFirst) != 0);

	return cordinats;
}