#pragma once
#include <iostream>
#include <conio.h>
#include "draw.h"
using namespace std;

#define BUTTON_ENTER 13
#define BUTTON_URROW_LEFT 75
#define BUTTON_URROW_RIGHT 77
#define BUTTON_URROW_UP 72
#define BUTTON_URROW_DOWN 80
#define BUTTON_ESC 27

Cursor Input(char** map, bool crossColorTurn);
