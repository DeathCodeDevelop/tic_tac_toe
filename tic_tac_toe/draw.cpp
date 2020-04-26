#include <iostream>
#include "draw.h"

enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void Draw(char** newMap, Cursor& cursor, bool crossTurn)
{
	const int SIZE = 5;
	char CROSS_IMAGE[SIZE][SIZE] =
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
	/*���� ����� ���� - �����. ���� ����� ������ - ������*/
	system("cls");
	system("color 0");

	for (size_t i = 0; i < 15; i++)
	{
		if (i == 0 || i == 5 || i == 10)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(White));
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
				SetConsoleTextAttribute(hConsole, (WORD)(White));
				cout << " #";
			}
			if ((i >= 0 && i < 5) && (j >= 0 && j < 5))
			{
				if (cursor.x == 0 && cursor.y == 0)
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Green));
					cout << " " << CURSOR_IMAGE[i][j];
				}
				else if (newMap[0][0] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << CROSS_IMAGE[i][j];
				}
				else if (newMap[0][0] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << NULL_IMAGE[i][j];
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 0 && i < 5) && (j >= 5 && j < 10))
			{
				if (cursor.x == 1 && cursor.y == 0)
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Green));
					cout << " " << CURSOR_IMAGE[i][j - 5];
				}
				else if (newMap[0][1] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << CROSS_IMAGE[i][j - 5];
				}
				else if (newMap[0][1] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << NULL_IMAGE[i][j - 5];
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 0 && i < 5) && (j >= 10 && j < 15))
			{
				if (cursor.x == 2 && cursor.y == 0)
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Green));
					cout << " " << CURSOR_IMAGE[i][j - 10];
				}
				else if (newMap[0][2] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << CROSS_IMAGE[i][j - 10];
				}
				else if (newMap[0][2] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << NULL_IMAGE[i][j - 10];
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 5 && i < 10) && (j >= 0 && j < 5))
			{
				if (cursor.x == 0 && cursor.y == 1)
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Green));
					cout << " " << CURSOR_IMAGE[i - 5][j];
				}
				else if (newMap[1][0] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << CROSS_IMAGE[i - 5][j];
				}
				else if (newMap[1][0] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << NULL_IMAGE[i - 5][j];
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 5 && i < 10) && (j >= 5 && j < 10))
			{
				if (cursor.x == 1 && cursor.y == 1)
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Green));
					cout << " " << CURSOR_IMAGE[i - 5][j - 5];
				}
				else if (newMap[1][1] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << CROSS_IMAGE[i - 5][j - 5];
				}
				else if (newMap[1][1] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << NULL_IMAGE[i - 5][j - 5];
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 5 && i < 10) && (j >= 10 && j < 15))
			{
				if (cursor.x == 2 && cursor.y == 1)
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Green));
					cout << " " << CURSOR_IMAGE[i - 5][j - 10];
				}
				else if (newMap[1][2] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << CROSS_IMAGE[i - 5][j - 10];
				}
				else if (newMap[1][2] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << NULL_IMAGE[i - 5][j - 10];
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 10 && i < 15) && (j >= 0 && j < 5))
			{
				if (cursor.x == 0 && cursor.y == 2)
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Green));
					cout << " " << CURSOR_IMAGE[i - 10][j];
				}
				else if (newMap[2][0] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << CROSS_IMAGE[i - 10][j];
				}
				else if (newMap[2][0] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << NULL_IMAGE[i - 10][j];
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 10 && i < 15) && (j >= 5 && j < 10))
			{
				if (cursor.x == 1 && cursor.y == 2)
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Green));
					cout << " " << CURSOR_IMAGE[i - 10][j - 5];
				}
				else if (newMap[2][1] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << CROSS_IMAGE[i - 10][j - 5];
				}
				else if (newMap[2][1] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << NULL_IMAGE[i - 10][j - 5];
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 10 && i < 15) && (j >= 10 && j < 15))
			{
				if (cursor.x == 2 && cursor.y == 2)
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Green));
					cout << " " << CURSOR_IMAGE[i - 10][j - 10];
				}
				else if (newMap[2][2] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << CROSS_IMAGE[i - 10][j - 10];
				}
				else if (newMap[2][2] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << NULL_IMAGE[i - 10][j - 10];
				}
				else
				{
					cout << "  ";
				}
			}
			if (j == 14)
			{
				SetConsoleTextAttribute(hConsole, (WORD)(White));
				cout << " #";
			}
		}
		if (i == 14)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(White));
			cout << endl;
			for (int i = 0; i < 15 + 4; i++)
			{
				cout << " #";
			}
		}
		cout << endl;
	}

	if (crossTurn)
	{
		cout << " x turn\n";
	}
	else
	{
		cout << " o turn\n";
	}
}