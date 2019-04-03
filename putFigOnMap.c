#include "fillit.h"

char **createMap(int length)
{
	char ** res = (char**)malloc(sizeof(char*) * (length + 1));
	res[length] = NULL;
	int i = 0;
	while (i < length)
	{
		res[i] = (char*)malloc(sizeof(char) * (length + 1));
		ft_memset(res[i], 46, length);
		res[i][length] = '\0';
		printf("%d - %s\n", i, res[i]);
		i++;
	}
	return res;
}



int putFigOnMap(char ** map, int r_0, int c_0, t_tetriminos * figure)
{
	int j = 0;
			    //  0 1  2 3  4 5
	//int arr[8] = {1,0, 1,1, 2,1};
	// x - column
	// y - row; 
	// 						row 				column
	// char block2 = map	[r_0 + arr[1]]		[c_0 + arr[0]];
	// char block3 = map	[r_0 + arr[3]]		[c_0 + arr[2]];
	// char block4 = map	[r_0 + arr[5]]		[c_0 + arr[4]];

	int length = ft_strlen(map[0]) - 1;
	if ((r_0 + figure->arr[1] <= length) && (r_0 + figure->arr[1] >= 0) && (c_0 + figure->arr[0] <= length) && (c_0 + figure->arr[0] >= 0))
		j++;
	if ((r_0 + figure->arr[3] <= length) && (r_0 + figure->arr[3] >= 0) && (c_0 + figure->arr[2] <= length) && (c_0 + figure->arr[2] >= 0))
		j++;
	if ((r_0 + figure->arr[5] <= length) && (r_0 + figure->arr[5] >= 0) && (c_0 + figure->arr[4] <= length) && (c_0 + figure->arr[4] >= 0))
		j++;
	if (map[r_0 + figure->arr[1]][c_0 + figure->arr[0]] == '.')
		j++;
	if (map[r_0 + figure->arr[3]][c_0 + figure->arr[2]] == '.')
		j++;
	if (map[r_0 + figure->arr[5]][c_0 + figure->arr[4]] == '.')
		j++;

	if (j == 6)
	{
		map[r_0][c_0] = figure->c;
		map[r_0 + figure->arr[1]][c_0 + figure->arr[0]] = figure->c;
		map[r_0 + figure->arr[3]][c_0 + figure->arr[2]] = figure->c;
		map[r_0 + figure->arr[5]][c_0 + figure->arr[4]] = figure->c;
		return 1;
	}
	else 
		return 0; 
}

// int main (void)
// {
// 	 
// }

int 	setFreeCell(int * coords, char ** map)
{
	int i = 0;
	int j = 0;
	int length = ft_strlen(map[0]);
	while (i < length)
	{
		while (map[i][j] != '\0' && map[i][j] != '.')
		{
			j++;
		}
		if (map[i][j] == '.')
		{
			coords[0] = i;
			coords[1] = j;
			return 1;
		}
		else 
		{
			i++; 
		}
	}
	return 0;
}

int main(int ac, char ** av)
{
	int coords [2] = {0, 0};
	t_tetriminos *head = NULL;
	t_tetriminos *cur;

	if (ac != 2)
		return -5; // show usage

	int status;

	status = readFile(av[1], &head);
	cur = head;
	cur->arr[0] = 1;
	cur->arr[1] = 0;
	cur->arr[2] = 1;
	cur->arr[3] = 1;
	cur->arr[4] = 2;
	cur->arr[5] = 1;


	char ** map = createMap(4);
	status = setFreeCell(coords, map);
	printf("%d - %d\n", coords[0], coords[1]);

	status = putFigOnMap(map, coords[0], coords[1], cur);
	
	printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	printf("%s\n", map[3]);
	
	status = setFreeCell(coords, map);
	printf("%d - %d\n", coords[0], coords[1]);

	cur = cur->next;
	status = putFigOnMap(map, coords[0], coords[1], cur);

	printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	printf("%s\n", map[3]);

	
	return 0;
}
