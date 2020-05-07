#include <iostream>
#include <ctime>
#include "draw.h"

void Draw(char** newMap, Cursor& cursor, bool crossTurn, int colorData[])
{
	srand(time(nullptr));

	const int SIZE = 5;
	char crossColor_IMAGE[SIZE][SIZE] =
	{
		{ '*', ' ', ' ', ' ', '*' },
		{ ' ', '*', ' ', '*', ' ' },
		{ ' ', ' ', '*', ' ', ' ' },
		{ ' ', '*', ' ', '*', ' ' },
		{ '*', ' ', ' ', ' ', '*' }
	};
	char NULL_IMAGE[SIZE][SIZE] =
	{
		{ ' ', '*', '*', '*', ' ' },
		{ '*', ' ', ' ', ' ', '*' },
		{ '*', ' ', ' ', ' ', '*' },
		{ '*', ' ', ' ', ' ', '*' },
		{ ' ', '*', '*', '*', ' ' }
	};
	char CURSOR_IMAGE[SIZE][SIZE] =
	{
		{ '*', '*', '*', ' ', ' ' },
		{ '*', '*', ' ', ' ', ' ' },
		{ '*', ' ', '*', ' ', ' ' },
		{ ' ', ' ', ' ', '*', ' ' },
		{ ' ', ' ', ' ', ' ', ' ' }
	};

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/*÷вет всего фона - белый. ÷вет всего текста - черный*/
	system("cls");
	system("color 0");

	int borderColor;
	int cursorColor;
	int crossColor;
	int nullColor;
	
	if (colorData[0] >= 16 || colorData[1] >= 16 || colorData[2] >= 16 || colorData[3] >= 16)
	{
		borderColor = rand() % 14 + 1;
		cursorColor = rand() % 14 + 1;
		crossColor = rand() % 14 + 1;
		nullColor = rand() % 14 + 1;
	}
	else 
	{
		borderColor = colorData[0];
		cursorColor = colorData[1];
		crossColor = colorData[2];
		nullColor = colorData[3];
	}	
	
	for (size_t i = 0; i < 15; i++)
	{
		if (i == 0 || i == 5 || i == 10)
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
			if (j == 0 || j == 5 || j == 10)
			{
				SetConsoleTextAttribute(hConsole, (WORD)(borderColor));
				cout << " #";
			}
			if (cursor.x == int(j / 5) && cursor.y == int(i / 5))
			{
				if (CURSOR_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)] != ' ')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(cursorColor));
					cout << " " << CURSOR_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)];
				}
				else if (newMap[int(i / 5)][int(j / 5)] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(crossColor));
					cout << " " << crossColor_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)];
				}
				else if (newMap[int(i / 5)][int(j / 5)] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(nullColor));
					cout << " " << NULL_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)];
				}
				else
				{
					cout << "  ";
				}
			}
			else if (newMap[int(i / 5)][int(j / 5)] == 'x')
			{
				SetConsoleTextAttribute(hConsole, (WORD)(crossColor));
				cout << " " << crossColor_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)];
			}
			else if (newMap[int(i / 5)][int(j / 5)] == 'o')
			{
				SetConsoleTextAttribute(hConsole, (WORD)(nullColor));
				cout << " " << NULL_IMAGE[i - 5 * (i / 5)][j - 5 * (j / 5)];
			}
			else
			{
				cout << "  ";
			}

			if (j == 14)
			{
				SetConsoleTextAttribute(hConsole, (WORD)(borderColor));
				cout << " #";
			}
		}
		if (i == 14)
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

	SetConsoleTextAttribute(hConsole, (WORD)(White));

	if (crossTurn)
	{
		cout << " x turn\n";
	}
	else
	{
		cout << " o turn\n";
	}
}