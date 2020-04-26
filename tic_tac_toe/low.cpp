#include "low.h"

Cordinats Low(char** map)
{
	srand(time(nullptr));
	
	Cordinats cordinats;
	do
	{
		cordinats.x = rand() % 3;
		cordinats.y = rand() % 3;
	} while (map[cordinats.y][cordinats.x] == 'x' || map[cordinats.y][cordinats.x] == 'o');

	return cordinats;
}