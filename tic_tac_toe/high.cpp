#include "high.h" 

Cordinats High(char** map, bool playerFirst)
{
	int symbol, enemySymbol;
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
	
	size_t turn = 0;

	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			if (map[i][j] == 'x' || map[i][j] == 'o')
				turn++;

	if (turn == 0)
	{
		return { 2, 0 };
	}
	else if (turn == 1)
	{
		if (map[0][0] == enemySymbol || map[2][2] == enemySymbol || map[0][2] == enemySymbol || map[2][0] == enemySymbol)
		{
			return { 1, 1 };
		}
		else if (map[1][0] == enemySymbol || map[0][1] == enemySymbol)
		{
			return { 0, 0 };
		}
		else if (map[1][2] == enemySymbol)
		{
			return { 2, 0 };
		}
		else if (map[1][1] == enemySymbol || map[2][1] == enemySymbol)
		{
			return { 0 , 2 };
		}
	}
		
	cordinats = Medium(map, playerFirst);

	return cordinats;
}