#include "medium.h"

Cordinats Medium(char** map, bool playerFirst)
{
	srand(time(nullptr));

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

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			newMap[i][j] = map[i][j];

	do
	{
		cordinats = Low(newMap);
		newMap[cordinats.y][cordinats.x] = symbol;

		if (Logic(newMap, playerFirst) == NOBODY_WON)
			break;

		count++;
	} while (Logic(newMap, playerFirst) != 0);

	return cordinats;
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
