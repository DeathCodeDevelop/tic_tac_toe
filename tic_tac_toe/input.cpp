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
	} while (THE_SELL_IS_NOT_EMPTY || X_IS_OUT_OF_BORDERS || Y_IS_OUT_OF_BORDERS);

	return cordinats;
}