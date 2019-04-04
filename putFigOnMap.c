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
		i++;
	}
	return res;
}

t_tetriminos *findFigInStr(int c, t_tetriminos **head)
{
	t_tetriminos * el = 
}

int putFigOnMap(char ** map, int r_0, int c_0, t_tetriminos * figure)
{
	int j = 0;
			    //  0 1  2 3  4 5  6,7
	//int arr[8] = {0,0, 1,0, 1,1, 2,1};
	// x - column
	// y - row; 
	// 						row 				column
	// char block2 = map	[r_0 + arr[1]]		[c_0 + arr[0]];
	// char block3 = map	[r_0 + arr[3]]		[c_0 + arr[2]];
	// char block4 = map	[r_0 + arr[5]]		[c_0 + arr[4]];

	int length = ft_strlen(map[0]) - 1;
	if ((r_0 + figure->arr[3] <= length) && (r_0 + figure->arr[3] >= 0) && (c_0 + figure->arr[2] <= length) && (c_0 + figure->arr[2] >= 0))
		j++;
	if ((r_0 + figure->arr[5] <= length) && (r_0 + figure->arr[5] >= 0) && (c_0 + figure->arr[4] <= length) && (c_0 + figure->arr[4] >= 0))
		j++;
	if ((r_0 + figure->arr[7] <= length) && (r_0 + figure->arr[7] >= 0) && (c_0 + figure->arr[6] <= length) && (c_0 + figure->arr[6] >= 0))
		j++;
	if (map[r_0 + figure->arr[3]][c_0 + figure->arr[2]] == '.')
		j++;
	if (map[r_0 + figure->arr[5]][c_0 + figure->arr[4]] == '.')
		j++;
	if (map[r_0 + figure->arr[7]][c_0 + figure->arr[6]] == '.')
		j++;

	if (j == 6)
	{
		map[r_0][c_0] = figure->c;
		map[r_0 + figure->arr[3]][c_0 + figure->arr[2]] = figure->c;
		map[r_0 + figure->arr[5]][c_0 + figure->arr[4]] = figure->c;
		map[r_0 + figure->arr[7]][c_0 + figure->arr[6]] = figure->c;
		figure->status = 1;
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
	
	char ** map = createMap(4);
	status = setFreeCell(coords, map);

	status = putFigOnMap(map, coords[0], coords[1], cur);
	printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	printf("%s\n", map[3]);
	
	
	status = setFreeCell(coords, map);

	cur = cur->next;
	status = putFigOnMap(map, coords[0], coords[1], cur);

	printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	printf("%s\n", map[3]);


	return 0;
}

stavim fig poka stavitsa
esli ne postavilas ->ischem druguyu fig poka oni ne finish; 
probuem drugie fig 
elsi vse fig pereprobovali i  oni ne stavyatsya s i-pustyh cells -> 


udalyaem prev figure stavim druguyu


esli figur net a yachejka odna pustaya -> znachit tak zhe rabotaem s i++-pustyh yacheek 

void rec_putFigOnMap(map, coords[0], coords[1], cur)
{
	while (status)
	{
		setFreeCell(coords, map);
		cur = findFigtoMap(t_tetriminos ** head);
		status = putFigOnMap(map, coords[0], coords[1], cur);
	}
	//if (all figures - in map) - done! i vyhod s recursion; 
	if (!status)
	{
		cur = findFigtoMap(t_tetriminos ** head);
		if (!cur)
			deMapFig(last);
				if (!whatTodeMap)
				{
					all_markers_to_0();
					empty_cell++;
					if (empy_cell + qty_fig * 4 > optimal_square)
						optimal_square_side++;
				}
					
		status = rec_putFigOnMap();
	}
	
}


int fig_counter = 0;

stavim fig poka stavitsa
while (status != -1 && fig_counter != total)
{
	status = putFigOnMap(map, coords[0], coords[1], cur);
	setFreeCell(coords, map);
	cur = findFigtoMap(t_tetriminos ** head);
	fig_counter++;
}

if (status == 0 && fig_counter != total)
{
	next = findFigtoMap(t_tetriminos ** head);
	status = putFigOnMap(map, coords[0], coords[1], cur);
	setFreeCell(coords, map);
	cur = findFigtoMap(t_tetriminos ** head);
	fig_counter++;
	}
		deMapCur

}


