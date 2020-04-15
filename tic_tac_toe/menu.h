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
	bool playWithComputer;
	int difficulty; // 0 - low, 1 - medium, 2 - hard
	bool youFirstPlayer;
};

Menu ShowMenu();
void ScreenImage(int cursorPosition, char** text, size_t size);
void ShowSpace(int count);
void Input(int& cursorPosition, bool& menuWork, int size, bool& returnMenu, int menuPosistion);
void MakeStructure(int* arr, Menu& menu);