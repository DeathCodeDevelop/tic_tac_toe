#pragma once
#include "logic.h"
#include "low.h"
#include "map.h"

Cordinats Medium(char** map, bool playerFirst);
bool MaybeSomeoneWon(char** map, Cordinats& cordinats, char symbol, size_t remainingTurns, bool playerFirst);