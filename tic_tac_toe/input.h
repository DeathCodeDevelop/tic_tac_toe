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
#define THE_SELL_IS_NOT_EMPTY (map[cordinats.y][cordinats.x] != ' ')
#define X_IS_OUT_OF_BORDERS (cordinats.x < 0 || cordinats.x > 2)
#define Y_IS_OUT_OF_BORDERS (cordinats.y < 0 || cordinats.y > 2)

Cursor Input(char** map, bool crossTurn, int colorData[]);
