#include "menu.h"

Menu ShowMenu()
{
	Menu menu;

	//Menu sizes

	const int MENU_QUANTITY = 5;
	const int MENU_SIZES[MENU_QUANTITY] = { 4, 4, 5, 18, 3 };

	//Menu

	MenuItem mainMenu[] =
	{
		{ "play with friend" },
		{ "play with computer" },
		{ "options" },
		{"exit"}
	};
	MenuItem optionsMenu[] =
	{
		{"borderColor"},
		{"cursorColor"},
		{"crossColor"},
		{"nullColor"},
		{"return"}
	};
	MenuItem difficaltyChooseMenu[] =
	{
		{"Low"},
		{"Medium"},
		{"High"},
		{"return"}
	};
	MenuItem colorChooseMenu[] =
	{
		{"Black"},
		{"Blue"},
		{"Green"},
		{"Cyan"},
		{"Red"},
		{"Magenta"},
		{"Brown"},
		{"LightGray"},
		{"DarkGray"},
		{"LightBlue"},
		{"LightGreen"},
		{"LightCyan"},
		{"LightRed"},
		{"LightMagenta"},
		{"Yellow"},
		{"White"},
		{"Epileptic"},
		{"return"}
	};
	MenuItem chooseWhoFirst[] =
	{
		{ "i am first" },
		{ "bot first" },
		{ "return" }
	};

	//menu

	int menuPosition = 0;
	int cursorPosition = 0;
	bool menuWork = true;
	bool menuChanged = true;
	int inputSize = MENU_SIZES[0];

	//color change

	int tempColor = -1;
	int tempColorIndex = -1;
	const int COLOR_SIZE = 4;
	int colorData[COLOR_SIZE] = { 15, 2, 4, 1 };

	//other options

	int difficalty = -1;
	bool youFirstPlayer = false;
	bool playWithComputer = true;
	bool exitTrue = false;


	ScreenImage(cursorPosition, mainMenu, MENU_SIZES[0], false);
	do
	{
		char answer = ' ';

		if (!menuChanged)
		{
			inputSize = MENU_SIZES[menuPosition];
			answer = MenuInput(cursorPosition, inputSize, menuPosition);
		}
		else
			menuChanged = false;

		switch (menuPosition)
		{
		case MAIN_MENU:
			ScreenImage(cursorPosition, mainMenu, MENU_SIZES[0], false);
			MainMenuFunctions(cursorPosition, menuPosition, menuWork, answer, playWithComputer, menuChanged, exitTrue);
			break;
		case DIFFICALTY_CHOOSE:
			ScreenImage(cursorPosition, difficaltyChooseMenu, MENU_SIZES[0], false);
			DifficaltyChooseMenuFunctions(cursorPosition, menuPosition, answer, difficalty, menuChanged);
			break;
		case OPTIONS_MENU:
			ScreenImage(cursorPosition, optionsMenu, MENU_SIZES[2], false);
			OptionsMenuFunctions(cursorPosition, menuPosition, answer, tempColorIndex, menuChanged);
			break;
		case COLOR_CHOOSE:
			ScreenImage(cursorPosition, colorChooseMenu, MENU_SIZES[3], true);
			ColorChooseMenuFunctions(cursorPosition, menuPosition, answer, colorData, tempColor, tempColorIndex, menuChanged);
			break;
		case WHO_FIRST_CHOOSE:
			ScreenImage(cursorPosition, chooseWhoFirst, MENU_SIZES[4], false);
			WhoFirstMenuFunctions(cursorPosition, menuPosition, menuWork, answer, menuChanged, youFirstPlayer);
			break;
		}
	} while (menuWork);

	MakeStruct(&menu, colorData, difficalty, youFirstPlayer, playWithComputer, exitTrue);

	cout << "borderColor:" << colorData[0] << endl;
	cout << "[1]" << colorData[1] << endl;
	cout << "[2]" << colorData[2] << endl;
	cout << "[3]" << colorData[3] << endl;
	cout << "difficalty = > " << difficalty << endl;
	cout << "i am first :" << youFirstPlayer << endl;
	cout << "play with computer :" << playWithComputer << endl;
	cout << "exitTrue :" << exitTrue << endl;

	return menu;
}

void ScreenImage(int cursorPosition, MenuItem* text, int size, bool chooseColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	system("color 0");

	const int IMAGE_SIZE = 49;
	const int GLOBAL_SPACE = 30;

	if (chooseColor && cursorPosition < 16)
		SetConsoleTextAttribute(hConsole, (WORD)(cursorPosition));
	else
		SetConsoleTextAttribute(hConsole, (WORD)(15));

	ShowSpace(GLOBAL_SPACE); cout << "|\\     /|      |\\     /|(  ____ \\      (  ___  )\n";
	ShowSpace(GLOBAL_SPACE); cout << "( \\   / )      | )   ( || (    \\/      | (   ) |\n";
	ShowSpace(GLOBAL_SPACE); cout << " \\ (_) /       | |   | || (_____       | |   | |\n";
	ShowSpace(GLOBAL_SPACE); cout << "  ) _ (        ( (   ) )(_____  )      | |   | |\n";
	ShowSpace(GLOBAL_SPACE); cout << " / ( ) \\        \\ \\_/ /       ) |      | |   | |\n";
	ShowSpace(GLOBAL_SPACE); cout << "( /   \\ )        \\   /  /\\____) |      | (___) |\n";
	ShowSpace(GLOBAL_SPACE); cout << "|/     \\|         \\_/   \\_______)      (_______)\n";
	ShowSpace(GLOBAL_SPACE);
	ShowSpace((IMAGE_SIZE - 6) / 2);
	cout << cursorPosition << " / " << size - 1 << "\n";

	SetConsoleTextAttribute(hConsole, (WORD)(15));

	int leftBorder = 0, rightBorder = 0;

	if (size <= 4)
	{
		rightBorder = size;
	}
	else
	{
		leftBorder = cursorPosition;
		rightBorder = cursorPosition + 4;
	}

	for (int i = leftBorder; i < rightBorder; i++)
	{
		int spaceCount = (IMAGE_SIZE - strlen(text[i].item) - 4) / 2;

		if (i > size - 1)
		{
			cout << endl;
			ShowSpace(GLOBAL_SPACE);
			ShowSpace((IMAGE_SIZE - 4) / 2);
			cout << "  " << "\n\n";
		}
		else if (cursorPosition == i)
		{
			ShowSpace(GLOBAL_SPACE);
			ShowSpace(spaceCount);

			for (size_t j = 0; j < strlen(text[i].item) + 4; j++)
			{
				cout << "#";
			}
			cout << endl;

			ShowSpace(GLOBAL_SPACE);
			ShowSpace(spaceCount);
			cout << "# " << text[i].item << " #\n";

			ShowSpace(GLOBAL_SPACE);
			ShowSpace(spaceCount);

			for (size_t j = 0; j < strlen(text[i].item) + 4; j++)
			{
				cout << "#";
			}

			cout << endl;
		}
		else
		{
			cout << endl;
			ShowSpace(GLOBAL_SPACE);
			ShowSpace(spaceCount);
			cout << "  " << text[i].item << "\n\n";
		}
	}

	cout << endl;
	ShowSpace(GLOBAL_SPACE);
	ShowSpace(13);
	cout << "W OR ARROW UP - UP\n";
	ShowSpace(GLOBAL_SPACE);
	ShowSpace(13);
	cout << "S OR ARROW UP - DOWN\n";
	ShowSpace(GLOBAL_SPACE);
	ShowSpace(13);
	cout << "F OR ENTER - CONFIRM\n";
	ShowSpace(GLOBAL_SPACE);
	ShowSpace(13);
	cout << "ESC - RETURN\n";
};

void ShowSpace(int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << " ";
	}
}

char MenuInput(int& cursorPosition, int size, int menuPosition)
{
	char answer = ' ';

	switch (_getch())
	{
	case 'w':case 'W':case BUTTON_URROW_UP:
		if (cursorPosition > 0)
			cursorPosition--;
		break;
	case 's':case 'S':case BUTTON_URROW_DOWN:
		if (cursorPosition < size - 1)
			cursorPosition++;
		break;
	case 'f':case 'F':case BUTTON_ENTER:
		answer = 'f';
		break;
	case BUTTON_ESC:
		answer = 'e';
		break;
	}

	return answer;
}

void MainMenuFunctions(int& cursorPosition, int& menuPosition, bool& menuWork, char answer, bool& playWithComputer, bool& menuChanged, bool& exitTrue)
{
	if (answer == 'f')
	{
		if (cursorPosition == 0)
		{
			menuWork = false;
			playWithComputer = false;
		}
		else if (cursorPosition == 1)
		{
			menuPosition = DIFFICALTY_CHOOSE;
			cursorPosition = 0;

			menuChanged = true;
		}
		else if (cursorPosition == 2)
		{
			menuPosition = OPTIONS_MENU;
			cursorPosition = 0;
			menuChanged = true;
		}
		else if (cursorPosition == 3)
		{
			exitTrue = true;
			menuWork = false;
		}
	}
	else if (answer == 'e')
	{
		exitTrue = true;
		menuWork = false;
	}
}

void ColorChooseMenuFunctions(int& cursorPosition, int& menuPosition, char answer, int colorData[], int& tempColor, int tempColorIndex, bool& menuChanged)
{
	if (answer == 'f')
	{
		if (cursorPosition >= 0 && cursorPosition <= 16)
		{
			colorData[tempColorIndex] = cursorPosition;
		}
		cursorPosition = 0;
		menuPosition = OPTIONS_MENU;
		menuChanged = true;
	}
	else if (answer == 'e')
	{
		menuPosition = OPTIONS_MENU;
		cursorPosition = 0;
		menuChanged = true;
	}
}

void DifficaltyChooseMenuFunctions(int& cursorPosition, int& menuPosition, char answer, int& difficalty, bool& menuChanged)
{
	if (answer == 'f')
	{
		if (cursorPosition == 3)
		{
			menuPosition = MAIN_MENU;
			cursorPosition = 0;
			menuChanged = true;
		}
		else
		{
			difficalty = cursorPosition;
			cursorPosition = 0;
			menuPosition = WHO_FIRST_CHOOSE;
			menuChanged = true;
		}
	}
	else if (answer == 'e')
	{
		menuPosition = MAIN_MENU;
		cursorPosition = 0;
		menuChanged = true;
	}
}

void WhoFirstMenuFunctions(int& cursorPosition, int& menuPosition, bool& menuWork, char answer, bool& menuChanged, bool& youFirstPlayer)
{
	if (answer == 'f')
	{
		if (cursorPosition == 0)
		{
			youFirstPlayer = true;
			menuWork = false;
		}
		else if (cursorPosition == 1)
		{
			youFirstPlayer = false;
			menuWork = false;
		}
		else if (cursorPosition == 2)
		{
			menuPosition = DIFFICALTY_CHOOSE;
			cursorPosition = 0;
			menuChanged = true;
		}
	}
	else if (answer == 'e')
	{
		menuPosition = DIFFICALTY_CHOOSE;
		cursorPosition = 0;
		menuChanged = true;
	}
}

void OptionsMenuFunctions(int& cursorPosition, int& menuPosition, char answer, int& tempColorIndex, bool& menuChanged)
{
	if (answer == 'f')
	{
		if (cursorPosition == 4)
		{
			cursorPosition = 0;
			menuPosition = MAIN_MENU;
			menuChanged = true;
		}
		else
		{
			tempColorIndex = cursorPosition;
			cursorPosition = 0;
			menuChanged = true;
			menuPosition = COLOR_CHOOSE;
		}
	}
	else if (answer == 'e')
	{
		cursorPosition = 0;
		menuPosition = MAIN_MENU;
		menuChanged = true;
	}
}

void MakeStruct(Menu* menu, int colorData[], int difficalty, bool youFirstPlayer, bool playWithComputer, bool exitTrue)
{
	menu->exitTrue = exitTrue;
	menu->playWithComputer = playWithComputer;
	menu->difficulty = difficalty;
	menu->youFirstPlayer = youFirstPlayer;
	for (int i = 0; i < 4; i++)
	{
		menu->colorData[i] = colorData[i];
	}
}