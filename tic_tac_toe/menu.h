#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

#define BUTTON_ENTER 13
#define BUTTON_URROW_UP 72
#define BUTTON_URROW_DOWN 80
#define BUTTON_ESC 27

struct Menu
{
	bool exitTrue = true;
	bool playWithComputer = 0;
	int difficulty = 0; // 0 - low, 1 - medium, 2 - hard
	bool youFirstPlayer = 0;
};

Menu ShowMenu();
void ScreenImage(int cursorPosition, char** text, size_t size);
void ShowSpace(int count);
void MenuInput(int& cursorPosition, bool& menuWork, int size, bool& returnMenu, int menuPosistion, bool& gameWork);
void MakeStructure(int* arr, Menu& menu);