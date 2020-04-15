

bool Logic(char** map, bool crossTurn)
{
	char symbol;

	if (crossTurn) 
		symbol = 'x';
	else
		symbol = 'o';	
	
	if (GorizontalCheck(map, symbol))
	{
		return false;
	}
	else if (VerticalCheck(map, symbol))
	{
		return false;
	}
	else if (DiagonalsCheck(map, symbol))
	{
		return false;
	}

	return true;
}

bool GorizontalCheck(char** map, char symbol)
{
	for (size_t temp = 0; temp < 3; temp++)
	{
		int count = 0;

		for (size_t i = 0; i < 3; i++)
		{
			if (map[temp][i] == symbol)
			{
				count++;
			}
		}

		if (count == 3)
		{
			return true;
		}
	}
	return false;
}

bool VerticalCheck(char** map, char symbol)
{
	for (size_t temp = 0; temp < 3; temp++)
	{
		int count = 0;

		for (size_t i = 0; i < 3; i++)
		{
			if (map[i][temp] == symbol)
			{
				count++;
			}
		}

		if (count == 3)
		{
			return true;
		}
	}

	return false;
}

bool DiagonalsCheck(char** map, char symbol)
{
	int count = 0;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (i == j)
			{
				if (map[i][j] == symbol)
				{
					count++;
				}
			}
		}
	}

	if (count == 3)
	{
		return true;
	}

	count = 0;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (i + j == 2)
			{
				if (map[i][j] == symbol)
				{
					count++;
				}
			}
		}
	}

	if (count == 3)
	{
		return true;
	}

	return false;
}