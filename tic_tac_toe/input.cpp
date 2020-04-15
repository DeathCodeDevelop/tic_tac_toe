#include "input.h"

Cordinats Input(char** map)
{
	Cordinats cordinats;

	do
	{
		cout << "enter x = > ";
		cin >> cordinats.x;
		cout << "enter y = > ";
		cin >> cordinats.y;
	} while (map[cordinats.x - 1][cordinats.y - 1] != ' ' || X_IS_OUT_OF_BORDERS || Y_IS_OUT_OF_BORDERS);

	return cordinats;
}