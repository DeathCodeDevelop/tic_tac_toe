#pragma once
#include <iostream>
using namespace std;

#define THE_SELL_IS_NOT_EMPTY (map[cordinats.x - 1][cordinats.y - 1] != ' ')
#define X_IS_OUT_OF_BORDERS (cordinats.x < 1 || cordinats.x > 3)
#define Y_IS_OUT_OF_BORDERS (cordinats.y < 1 || cordinats.y > 3)

struct Cordinats 
{
	int x;
	int y;
};

Cordinats Input(char** map);