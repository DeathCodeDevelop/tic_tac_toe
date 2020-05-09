#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

#define BUTTON_ENTER 13
#define BUTTON_URROW_UP 72
#define BUTTON_URROW_DOWN 80
#define BUTTON_ESC 27
#define MAIN_MENU 0
#define DIFFICALTY_CHOOSE 1
#define OPTIONS_MENU 2
#define COLOR_CHOOSE 3
#define WHO_FIRST_CHOOSE 4

struct Menu
{
	bool exitTrue = true;
	bool playWithComputer = 0;
	int difficulty = 0; // 0 - low, 1 - medium, 2 - hard
	bool youFirstPlayer = 0;
	int colorData[4] = { 15, 2, 4, 1 };
};

struct MenuItem
{
	char item[30] = "";
};

Menu ShowMenu();
void ScreenImage(int cursorPosition, MenuItem* text, int size, bool chooseColor);
void ShowSpace(int count);
char MenuInput(int& cursorPosition, int size, int menuPosition);

void MainMenuFunctions(int& cursorPosition, int& menuPosition, bool& menuWork, char answer, bool& playWithComputer, bool& menuChanged, bool& exitTrue);
void ColorChooseMenuFunctions(int& cursorPosition, int& menuPosition, char answer, int colorData[], int& tempColor, int tempColorIndex, bool& menuChanged);
void DifficaltyChooseMenuFunctions(int& cursorPosition, int& menuPosition, char answer, int& difficalty, bool& menuChanged);
void WhoFirstMenuFunctions(int& cursorPosition, int& menuPosition, bool& menuWork, char answer, bool& menuChanged, bool& youFirstPlayer);
void OptionsMenuFunctions(int& cursorPosition, int& menuPosition, char answer, int& tempColorIndex, bool& menuChanged);
void MakeStruct(Menu* menu, int colorData[], int difficalty, bool youFirstPlayer, bool playWithComputer, bool exitTrue);