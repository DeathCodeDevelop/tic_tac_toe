#pragma once

#define WIN 0
#define NONE 1
#define NOBODY_WON 2

int Logic(char** map, bool crossTurn);
bool GorizontalCheck(char** map, char symbol);
bool VerticalCheck(char** map, char symbol);
bool DiagonalsCheck(char** map, char symbol);