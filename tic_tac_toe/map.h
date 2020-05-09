#pragma once

char** CreateNewMap(size_t size);
void CopyMap(char** map, char** newMap, size_t size);
void DeleteMap(char** map, size_t size);