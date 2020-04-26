#pragma once

int Logic(char** map, bool crossTurn);
bool GorizontalCheck(char** map, char symbol);
bool VerticalCheck(char** map, char symbol);
bool DiagonalsCheck(char** map, char symbol);