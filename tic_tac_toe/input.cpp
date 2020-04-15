#include "input.h"

#define THE_SELL_IS_NOT_EMPTY (map[cordinats.y][cordinats.x] != ' ')
#define X_IS_OUT_OF_BORDERS (cordinats.x < 0 || cordinats.x > 2)
#define Y_IS_OUT_OF_BORDERS (cordinats.y < 0 || cordinats.y > 2)

Cordinats Input(char** map)
{
	Cordinats cordinats;

	do
	{
		cout << "enter x = > ";
		cin >> cordinats.x;
		cout << "enter y = > ";
		cin >> cordinats.y;

		if (THE_SELL_IS_NOT_EMPTY)
		{
			continue;
		}
	} while ( X_IS_OUT_OF_BORDERS || Y_IS_OUT_OF_BORDERS);

	return cordinats;
}