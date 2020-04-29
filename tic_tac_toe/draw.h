#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

struct Cursor
{
	int x;
	int y;
};

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
	Lightnull = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightcrossColor = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void Draw(char** newMap, Cursor& cursor, bool crossColorTurn);
