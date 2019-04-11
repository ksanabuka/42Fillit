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

char **resizeMap(char *** map, t_tetriminos **head)
{
	char ** tmp;
	tmp = createMap((*head)->curmap_length);
	freemap(*map);
	*map = tmp;
	return *map;
}


void freemap(char ** map)
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

int  setFigStatus(int status, int curStatus, t_tetriminos **head)
{
	t_tetriminos * el;
	el = *head;

		while (el)
		{
			if (el->status == curStatus)
				el->status = status; 

			else if (curStatus != -1 && curStatus != 0 && curStatus != 1)
			{
				el->wasAt00 = 0;

				el->status = status; 
			}
			el = el->next; 
		}
	
	return status; 

}


int countStatus(int status, t_tetriminos **head)
{
	t_tetriminos * el;
	el = *head;
	int minus1 = 0;
	int one = 0;
	int zero = 0; 
		
		while (el)
		{
			if (el->status == -1)
				minus1++;
			else if (el->status == 0)
				zero++;
			else if (el->status == 1)
				one++;
			el = el->next; 
		}

		if (status == -1)
			return minus1;
		if (status == 0)
			return zero;
		else 
			return one; 
}

t_tetriminos *findFigtoMap(t_tetriminos **head)
{
	t_tetriminos * el;
	el = *head;
		
		while (el)
		{
			if (!isMapped(head, el))
				return el;
			el = el->next; 
		}
		return 0;
}

void addToStack(t_tetriminos * figure, t_tetriminos ** head)
{
	int i = 0;
	while (i < 26)
	{
		if ((*head)->stackMappedFigs[i] == 0)
		{
			(*head)->stackMappedFigs[i] = figure->c;
			return ;
		}
		i++;
	}
}

t_tetriminos * popFromStack_Str(t_tetriminos ** head)
{
	t_tetriminos * el; 
	int i = 0;
	int tmp = 0;

	while (i < 26)
	{
		if ((*head)->stackMappedFigs[i] == 0)
		{
			if (i - 1 >= 0)
			{
				tmp = (*head)->stackMappedFigs[i - 1];
				(*head)->stackMappedFigs[i - 1] = 0;
				break ;
			}
		}
		i++;
	}

	if (i == 26 && (*head)->stackMappedFigs[i - 1] != 0)
	{
		tmp = (*head)->stackMappedFigs[i - 1]; 
		(*head)->stackMappedFigs[i - 1] = 0;	
	}

	el = *head;
	while (el)
	{
		if (el->c == tmp)
			return el;
		el = el->next; 
	}
	return 0;
}

int putFigOnMap(char ** map, int * coords, t_tetriminos * figure, t_tetriminos ** head)
{
	int j = 0;
	int r_0 = coords[0];
	int c_0 = coords[1];

			    //  0 1  2 3  4 5  6,7
	//int arr[8] = {0,0, 0,1, 0,2, 0,3};
	// x - column
	// y - row; 
	// 						row 				column
	// char block2 = map	[r_0 + arr[1]]		[c_0 + arr[0]];
	// char block3 = map	[r_0 + arr[3]]		[c_0 + arr[2]];
	// char block4 = map	[r_0 + arr[5]]		[c_0 + arr[4]];
	//printf("%d %d\n %d, %d,%d,%d,%d,%d,%d,%d\n\n\n", r_0, c_0, figure->arr[0],figure->arr[1],figure->arr[2],figure->arr[3],figure->arr[4],figure->arr[5],figure->arr[6],figure->arr[7] );
	int length = ft_strlen(map[0]) - 1;
	if ((r_0 + figure->arr[3] <= length) && (r_0 + figure->arr[3] >= 0) && (c_0 + figure->arr[2] <= length) && (c_0 + figure->arr[2] >= 0))
		j++;
	if ((r_0 + figure->arr[5] <= length) && (r_0 + figure->arr[5] >= 0) && (c_0 + figure->arr[4] <= length) && (c_0 + figure->arr[4] >= 0))
		j++;
	if ((r_0 + figure->arr[7] <= length) && (r_0 + figure->arr[7] >= 0) && (c_0 + figure->arr[6] <= length) && (c_0 + figure->arr[6] >= 0))
		j++;
	if (j == 3)
	{
		if (map[r_0 + figure->arr[3]][c_0 + figure->arr[2]] == '.')
			j++;
		if (map[r_0 + figure->arr[5]][c_0 + figure->arr[4]] == '.')
			j++;
		if (map[r_0 + figure->arr[7]][c_0 + figure->arr[6]] == '.')
			j++;
	}

	if (j == 6)
	{
		map[r_0][c_0] = figure->c;
		map[r_0 + figure->arr[3]][c_0 + figure->arr[2]] = figure->c;
		map[r_0 + figure->arr[5]][c_0 + figure->arr[4]] = figure->c;
		map[r_0 + figure->arr[7]][c_0 + figure->arr[6]] = figure->c;
		figure->status = 1;

		addFigToSS(head, figure, (*head)->level);
		return 1;
	}
	else 
	{
		if (r_0 == 0 && c_0 == 0)
		{
			addFigToSS_Beg00(head, figure);
			return 0;
		}
		addFigToSS(head, figure, (*head)->level);
		figure->status = -1;
		return 0; 
	}
}

void deMapFig(char ** map, t_tetriminos * figure)
{
	int i = 0;
	char *tmp;

	while (i < (int)ft_strlen(map[0]))
	{
		
		while (((tmp = ft_strchr(map[i], figure->c) )!= NULL))
			*tmp = '.';
		i++;
	}	
}
void mark_cur_fig_minus(t_tetriminos * figure)
{
	figure->status = -1;
}

void displayMap(char ** map)
{
	int lenght = ft_strlen(map[0]);
	int i = 0;
	int j = 0;

	while (i < lenght)
	{
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		i++;
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

int checkAllStatus(t_tetriminos ** head, int status)
{
	t_tetriminos * el;
	el = *head;
		
		while (el)
		{
			if (el->status != status)
				return 0;
			el = el->next;
		}
		return 1;
}

int 	setFreeCell(int * coords, char ** map)
{
	int i = 0;
	int j = 0;
	int length = ft_strlen(map[0]);
	while (i < length)
	{
		j = 0;
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

// void setLastMappedFig(t_tetriminos *cur, t_tetriminos **head)
// {
// 	t_tetriminos * el;
// 	el = *head;
		
// 		while (el)
// 		{
// 			if (el == cur)
// 				el->amIlast = 1;
// 			else if (el->amIlast != 0)
// 				el->amIlast = 0;
// 			el = el->next;
// 		}
// }

// t_tetriminos *LastMappedFig(t_tetriminos **head)
// {
// 	t_tetriminos * el;
// 	el = *head;
		
// 		while (el)
// 		{
// 			if (el->amIlast != 0)
// 				return el;
// 			el = el->next;
// 		}
// 		return 0;
// }


void printStructure(t_tetriminos ** head)
{
		t_tetriminos * el;
		el = *head;
		
		while (el)
		{
			//printf("status:	%d, c:	%d, wasAt00:	%d, qty_fig:	%d, curmap_length:	%d\nbuffer:	%s\n arr:	%d, %d, %d, %d,%d,%d,%d,%d\n\n\n", el->status, el->c, el->wasAt00, el->qty_fig, el->curmap_length, el->buffer, el->arr[0], el->arr[1],el->arr[2],el->arr[3],el->arr[4],el->arr[5],el->arr[6],el->arr[7] );
			el = el->next;
		}
}

