#include <iostream>
#include <ctime>
#include "draw.h"

void Draw(char** newMap, Cursor& cursor, bool crossTurn, int colorData[])
{
	/*
		this function displays the contents of the map, borders and the cursor
	*/

	srand(time(nullptr));

	const size_t SIZE = 5;
	char crossColor_IMAGE[SIZE][SIZE] = // cross image
	{
		{ '*', ' ', ' ', ' ', '*' },
		{ ' ', '*', ' ', '*', ' ' },
		{ ' ', ' ', '*', ' ', ' ' },
		{ ' ', '*', ' ', '*', ' ' },
		{ '*', ' ', ' ', ' ', '*' }
	};
	char NULL_IMAGE[SIZE][SIZE] =		// null image
	{
		{ ' ', '*', '*', '*', ' ' },
		{ '*', ' ', ' ', ' ', '*' },
		{ '*', ' ', ' ', ' ', '*' },
		{ '*', ' ', ' ', ' ', '*' },
		{ ' ', '*', '*', '*', ' ' }
	};
	char CURSOR_IMAGE[SIZE][SIZE] =		// cursor image
	{
		{ '*', '*', '*', ' ', ' ' },
		{ '*', '*', ' ', ' ', ' ' },
		{ '*', ' ', '*', ' ', ' ' },
		{ ' ', ' ', ' ', '*', ' ' },
		{ ' ', ' ', ' ', ' ', ' ' }
	};

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // отримати налаштування консолі

	system("cls");
	system("color 0");

	int borderColor;
	int cursorColor;
	int crossColor;
	int nullColor;
	
	if (colorData[0] >= 16 || colorData[1] >= 16 || colorData[2] >= 16 || colorData[3] >= 16) // check epileptic mode
	{
		borderColor = rand() % 14 + 1;
		cursorColor = rand() % 14 + 1;
		crossColor = rand() % 14 + 1;
		nullColor = rand() % 14 + 1;
	}
	else // else set colors
	{
		borderColor = colorData[0];
		cursorColor = colorData[1];
		crossColor = colorData[2];
		nullColor = colorData[3];
	}	
	
	for (size_t i = 0; i < 15; i++)
	{
		if (i == 0 || i == 5 || i == 10) // show horizontal borders
		{
			SetConsoleTextAttribute(hConsole, (WORD)(borderColor));
			for (int i = 0; i < 15 + 4; i++)
			{
				cout << " #";
			}
			cout << endl;
		}
		for (size_t j = 0; j < 15; j++)
		{
			if (j == 0 || j == 5 || j == 10) // show vertical borders
			{
				SetConsoleTextAttribute(hConsole, (WORD)(borderColor));
				cout << " #";
			}
			if (cursor.x == int(j / 5) && cursor.y == int(i / 5)) // show cursor
			{
				if (CURSOR_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)] != ' ') // if cursor in this place not fade then show cursor
				{
					SetConsoleTextAttribute(hConsole, (WORD)(cursorColor));
					cout << " " << CURSOR_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)];
				}
				else if (newMap[int(i / 5)][int(j / 5)] == 'x') // if cursor fade and cross in this place then show cross
				{
					SetConsoleTextAttribute(hConsole, (WORD)(crossColor));
					cout << " " << crossColor_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)];
				}
				else if (newMap[int(i / 5)][int(j / 5)] == 'o') // if cursor fade and null in this place then show cross
				{
					SetConsoleTextAttribute(hConsole, (WORD)(nullColor));
					cout << " " << NULL_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)];
				}
				else
				{
					cout << "  ";
				}
			}
			else if (newMap[int(i / 5)][int(j / 5)] == 'x') // show cross
			{
				SetConsoleTextAttribute(hConsole, (WORD)(crossColor));
				cout << " " << crossColor_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)];
			}
			else if (newMap[int(i / 5)][int(j / 5)] == 'o') // show null
			{
				SetConsoleTextAttribute(hConsole, (WORD)(nullColor));
				cout << " " << NULL_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)];
			}
			else
			{
				cout << "  ";
			}

			if (j == 14) // show last vertical border
			{
				SetConsoleTextAttribute(hConsole, (WORD)(borderColor));
				cout << " #";
			}
		}
		if (i == 14)// show last horizontal 
		{
			SetConsoleTextAttribute(hConsole, (WORD)(borderColor));
			cout << endl;
			for (int i = 0; i < 15 + 4; i++)
			{
				cout << " #";
			}
		}
		cout << endl;
	}

	SetConsoleTextAttribute(hConsole, (WORD)(White)); // set white color to show text

	if (crossTurn)
	{
		cout << " x turn\n";
	}
	else
	{
		cout << " o turn\n";
	}
}