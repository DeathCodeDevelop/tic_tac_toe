#include "input.h"

#define THE_SELL_IS_NOT_EMPTY (map[cordinats.y][cordinats.x] != ' ')
#define X_IS_OUT_OF_BORDERS (cordinats.x < 0 || cordinats.x > 2)
#define Y_IS_OUT_OF_BORDERS (cordinats.y < 0 || cordinats.y > 2)

Cursor Input(char** map, bool crossTurn)
{
	Cursor cursor;
	bool inputWork = true;

	cursor.x = 0;
	cursor.y = 0;

	Draw(map, cursor, crossTurn);

	do
	{
		if (_kbhit()) 
		{
			switch (_getch())
			{
			case 'w':case 'W':case BUTTON_URROW_UP:
				if (cursor.y > 0)
					cursor.y--;
				break;
			case 's':case 'S':case BUTTON_URROW_DOWN:
				if (cursor.y < 2)
					cursor.y++;
				break;
			case 'a':case 'A':case BUTTON_URROW_LEFT:
				if (cursor.x > 0)
					cursor.x--;
				break;
			case 'd':case 'D':case BUTTON_URROW_RIGHT:
				if (cursor.x < 2)
					cursor.x++;
				break;
			case 'f':case 'F':case BUTTON_ENTER:
				if (map[cursor.y][cursor.x] == 'x' || map[cursor.y][cursor.x] == 'o')
					continue;
				if (crossTurn)
					map[cursor.y][cursor.x] = 'x';
				else
					map[cursor.y][cursor.x] = 'o';

				cursor.x = -1;
				cursor.y = -1;

				Draw(map, cursor, crossTurn);
				
				inputWork = false;
				break;
			}
			Draw(map, cursor, crossTurn);
		}
	} while(inputWork);

	

	return cursor;
}