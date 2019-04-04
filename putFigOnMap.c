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

void **freemap(char ** map)
{
	int length = ft_strlen(map[0]);
	int i = 0;
	while (i < length)
	{
		free(map[i]);
		i++; 
	}
	free(map);
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
	{
		figure->status = -1;
		return 0; 
	}
}

int deMapFig(char ** map, t_tetriminos ** head, t_tetriminos * figure)
{
	int i = 0;
	int j = 0;
	char *tmp;

	while (i < ft_strlen(map[0]))
	{
		
		while ((tmp = ft_strchr(map[i], figure->c) != NULL))
			*tmp = '.';
		i++;
	}
	figure->status = -1;
	
}
void mark_cur_fig_minus(t_tetriminos * figure)
{
	figure->status = -1;
}
void StatusMinusToZero(t_tetriminos ** head)
{
	t_tetriminos * el;
	el = *head;
		
		while (el)
		{
			if (el->status == -1)
				el->status = 0;
			el = el->next; 
		}
}



int WasAt00(t_tetriminos ** head)
{
	t_tetriminos * el;
	el = *head;
		
		while (el)
		{
			if (el->wasAt00 != 1)
				return 0;
			el = el->next;
		}
		return 1;
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

void all_markers_to_0(t_tetriminos ** head)
{
	t_tetriminos * el;
	el = *head;
		
		while (el)
		{
			el->wasAt00 = 0;
			el->status = 0;
			el = el->next;
		}
}

// stavim fig poka stavitsa
// esli ne postavilas ->ischem druguyu fig poka oni ne finish; 
// probuem drugie fig 
// elsi vse fig pereprobovali i  oni ne stavyatsya s i-pustyh cells -> 


// udalyaem prev figure stavim druguyu


// esli figur net a yachejka odna pustaya -> znachit tak zhe rabotaem s i++-pustyh yacheek 

void rec_putFigOnMap(map, coords[0], coords[1], cur)
{
	while (status)
	{
		setFreeCell(coords, map);
		cur = findFigtoMap(t_tetriminos ** head);
		status = putFigOnMap(map, coords[0], coords[1], cur);
		if (status)
			t_tetriminos * last = cur;

		if (fig_counter == count_1())
			display_map(); 
		if (status)
			all_-1_to_0();

	}
	//if (all figures - in map) - done! i vyhod s recursion; 
	char ** tmp; 
	if (!status)
	{
		cur = findFigtoMap(t_tetriminos ** head);
		

		

		if (!cur)
		{
			StatusMinusToZero(t_tetriminos ** head)
			deMapFig(map, head, figure);

			if (!cur && WasAt00(head) == 1)
			{
				all_markers_to_0(head);
				empty_cell++;
				if (empy_cell + (*head)->qty_fig) * 4 > ft_strlen(map[0]) * ft_strlen(map[0]))
				{
					tmp = createMap(ft_strlen(map[0]) + 1);
					freemap(map);
					map = tmp;
				}
					
			}
		}


		status = rec_putFigOnMap(map, coords[0], coords[1], cur);
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


