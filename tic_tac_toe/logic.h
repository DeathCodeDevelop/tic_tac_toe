#pragma once

#define WIN 1
#define NONE 0
#define NOBODY_WON 2

int Logic(char** map, bool crossTurn);
bool GorizontalCheck(char** map, char symbol);
bool VerticalCheck(char** map, char symbol);
bool DiagonalsCheck(char** map, char symbol);