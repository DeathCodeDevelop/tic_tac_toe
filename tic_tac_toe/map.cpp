char** CreateNewMap(size_t size)
{
	/*
		this function create new game map
	*/
	
	char** newMap = new char* [size];

	for (size_t i = 0; i < size; i++)
	{
		newMap[i] = new char[size];
	}

	return newMap;
}

void CopyMap(char** map, char** newMap, size_t size) 
{
	/*
		this function copy old map to new map
	*/

	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			newMap[i][j] = map[i][j];
}

void DeleteMap(char** map, size_t size) 
{
	/*
		this function delete map
	*/

	for (size_t i = 0; i < size; i++)
	{
		delete[] map[i];
	}
	delete[] map;
}