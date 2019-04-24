#include "fillit.h"

char **createMap(int length)
{
	char ** res = (char**)malloc(sizeof(char*) * (length));
	int i = 0;
	while (i < length)
	{
		res[i] = (char*)malloc(sizeof(char) * (length + 1));
		ft_memset(res[i], 46, length);
		res[i][length] = '\0';
		i++;
	}
	return res;
}


int canPutFigOnMap(char ** map,  int r_0,  int c_0, t_tetr * figure, t_tetr ** head)
{
	int j = 0;
	int length = (*head)->curmap_length - 1;
	if ((r_0 + figure->arr[1] <= length) && (r_0 + figure->arr[1] >= 0) && (c_0 + figure->arr[0] <= length) && (c_0 + figure->arr[0] >= 0))
		j++;
	if ((r_0 + figure->arr[3] <= length) && (r_0 + figure->arr[3] >= 0) && (c_0 + figure->arr[2] <= length) && (c_0 + figure->arr[2] >= 0))
		j++;
	if ((r_0 + figure->arr[5] <= length) && (r_0 + figure->arr[5] >= 0) && (c_0 + figure->arr[4] <= length) && (c_0 + figure->arr[4] >= 0))
		j++;
	if ((r_0 + figure->arr[7] <= length) && (r_0 + figure->arr[7] >= 0) && (c_0 + figure->arr[6] <= length) && (c_0 + figure->arr[6] >= 0))
		j++;
	if (j == 4)
	{
		if (map[r_0 + figure->arr[1]][c_0 + figure->arr[0]] == '.')
			j++;
		if (map[r_0 + figure->arr[3]][c_0 + figure->arr[2]] == '.')
			j++;
		if (map[r_0 + figure->arr[5]][c_0 + figure->arr[4]] == '.')
			j++;
		if (map[r_0 + figure->arr[7]][c_0 + figure->arr[6]] == '.')
			j++;
	}

	if (j == 8)
	{
		return 1;
	}
	else 
	{
		return 0; 
	}
}

void PutFigOnMap(char ** map,  int r_0,  int c_0, t_tetr * figure)
{
	map[r_0][c_0] = figure->c;
	map[r_0 + figure->arr[3]][c_0 + figure->arr[2]] = figure->c;
	map[r_0 + figure->arr[5]][c_0 + figure->arr[4]] = figure->c;
	map[r_0 + figure->arr[7]][c_0 + figure->arr[6]] = figure->c;
}

void deMapFig(char ** map, t_tetr * figure, t_tetr ** head)
{
	int i = 0;
	char *tmp;

	while (i < (*head)->curmap_length)
	{
		
		while (((tmp = ft_strchr(map[i], figure->c) )!= NULL))
			*tmp = '.';
		i++;
	}	
}


void displayMap(char ** map, t_tetr ** head)
{
	int lenght = (*head)->curmap_length;
	int j;
	int i = 0;

	while (i < lenght)
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
