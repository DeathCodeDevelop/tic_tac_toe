#include <iostream>
#include "draw.h"
#include <windows.h>
using namespace std;

void Draw(const char* NULL_IMAGE, const char* CROSS_IMAGE, char* newMap)
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/*÷вет всего фона - белый. ÷вет всего текста - черный*/
	system("cls");
	system("color 0");

	char map[3][3] =
	{
		{ 'x', 'o', 'x' },
		{ 'o', 'x', 'o' },
		{ 'x', 'o', 'x'}
	};

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			map[i][j] = *(newMap + i * 3 + j);
		}
	}

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
				if (map[0][0] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << *(CROSS_IMAGE + i * 5 + j);
				}
				else if (map[0][0] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << *(NULL_IMAGE + i * 5 + j);
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 0 && i < 5) && (j >= 5 && j < 10))
			{
				if (map[0][1] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << *(CROSS_IMAGE + i * 5 + (j - 5));
				}
				else if (map[0][1] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << *(NULL_IMAGE + i * 5 + (j - 5));
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 0 && i < 5) && (j >= 10 && j < 15))
			{
				if (map[0][2] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << *(CROSS_IMAGE + i * 5 + (j - 10));
				}
				else if (map[0][2] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << *(NULL_IMAGE + i * 5 + (j - 10));
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 5 && i < 10) && (j >= 0 && j < 5))
			{
				if (map[1][0] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << *(CROSS_IMAGE + (i - 5) * 5 + j);
				}
				else if (map[1][0] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << *(NULL_IMAGE + (i - 5) * 5 + j);
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 5 && i < 10) && (j >= 5 && j < 10))
			{
				if (map[1][1] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << *(CROSS_IMAGE + (i - 5) * 5 + (j - 5));
				}
				else if (map[1][1] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << *(NULL_IMAGE + (i - 5) * 5 + (j - 5));
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 5 && i < 10) && (j >= 10 && j < 15))
			{
				if (map[1][2] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << *(CROSS_IMAGE + (i - 5) * 5 + (j - 10));
				}
				else if (map[1][2] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << *(NULL_IMAGE + (i - 5) * 5 + (j - 10));
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 10 && i < 15) && (j >= 0 && j < 5))
			{
				if (map[2][0] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << *(CROSS_IMAGE + (i - 10) * 5 + j);
				}
				else if (map[2][0] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << *(NULL_IMAGE + (i - 10) * 5 + j);
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 10 && i < 15) && (j >= 5 && j < 10))
			{
				if (map[2][1] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << *(CROSS_IMAGE + (i - 10) * 5 + (j - 5));
				}
				else if (map[2][1] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << *(NULL_IMAGE + (i - 10) * 5 + (j - 5));
				}
				else
				{
					cout << "  ";
				}
			}
			else if ((i >= 10 && i < 15) && (j >= 10 && j < 15))
			{
				if (map[2][2] == 'x')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Red));
					cout << " " << *(CROSS_IMAGE + (i - 10) * 5 + (j - 10));
				}
				else if (map[2][2] == 'o')
				{
					SetConsoleTextAttribute(hConsole, (WORD)(Blue));
					cout << " " << *(NULL_IMAGE + (i - 10) * 5 + (j - 10));
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
}