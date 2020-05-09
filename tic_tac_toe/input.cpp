#include "input.h"

Cursor Input(char** map, bool crossTurn, int colorData[])
{
	/*
		this function is a keyboard input
	*/
	
	Cursor cursor = { 0, 0 }; // set default cursor place
	bool inputWork = true;

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

				inputWork = false;
				break;
			}
			Draw(map, cursor, crossTurn, colorData);
		}
	} while(inputWork);

	

	return cursor;
}