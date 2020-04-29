char** CreatenewMap(int rows, int cols)
{
	char** newMap = new char* [rows];

	for (int i = 0; i < rows; i++)
	{
		newMap[i] = new char[cols];
	}

	return newMap;
}

void CopyMap(char** map, char** newMap, size_t size) 
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			newMap[i][j] = map[i][j];
}