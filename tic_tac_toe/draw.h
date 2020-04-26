#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

struct Cursor
{
	int x;
	int y;
};

void Draw(char** newMap, Cursor& cursor, bool crossTurn);