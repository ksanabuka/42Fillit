#include "fillit.h"

void createStackStatus(t_tetriminos **head)
{
	(*head)->stackStatus = (char**)malloc(sizeof(char*) * 27);
	int  i = 0;
	int c = 26;

	while (i < 26)
	{
		(*head)->stackStatus[i] = (char*)malloc(sizeof(char) * (c + 1));
		ft_bzero((*head)->stackStatus[i], c + 1);
		i++;
		c--;
	}
	(*head)->stackStatus[26] = NULL;
}


void addFigToSS(t_tetriminos ** head, t_tetriminos * figure, int level)
{
	int i = 0;
	
	while (i != level)
		i++;
	
	int j = 0; 
	while ((*head)->stackStatus[i][j] != '\0' && j < 26 - level)
		j++;
	if ((*head)->stackStatus[i][j] == '\0' && j < 26 - level)
		(*head)->stackStatus[i][j] = figure->c;
}

void addFigToSS_Beg00(t_tetriminos ** head, t_tetriminos * figure)
{
	char *tmp = ft_strdup((*head)->stackStatus[0]);
	(*head)->stackStatus[0][0] = figure->c;
	(*head)->stackStatus[0][1] = '\0';
	ft_strcat((*head)->stackStatus[0], tmp);
	free(tmp);	
}

void delLastLevelFromSS(t_tetriminos ** head)
{
	int j = 0; 
	while ((*head)->stackStatus[(*head)->level][j] != '\0')
	{
		j++;
	}

	while(j >= 0)
	{
		(*head)->stackStatus[(*head)->level][--j] = '\0';
	}
}

void setEmptyCell(int *coords, char **map)
{
	map[coords[0]][coords[1]] ='*';
}			



int isMapped(t_tetriminos ** head, t_tetriminos * figure)
{

	int i = 0; 
	int j;

	while (i < (*head)->level)
	{
		j = 0;
		while ((*head)->stackStatus[i][j] != '\0')
			j++;
		if ((*head)->stackStatus[i][j] == '\0' && j > 0 && (*head)->stackStatus[i][j - 1] == figure->c)
			return 1; 
		i++;
	}

	j = 0;
	if (i == (*head)->level)

		while ((*head)->stackStatus[i][j] != '\0')
		{
			if ((*head)->stackStatus[i][j] == figure->c)
				return 1;
			else 
				j++;
		}	
	return 0;
}

t_tetriminos * findLastMappedFig(t_tetriminos ** head)
{
	int j = 0;
	int letter; 
	while ((*head)->stackStatus[(*head)->level][j] != '\0')
		j++;

	if (((*head)->stackStatus[(*head)->level][j] == '\0') && j > 0)
		letter = (*head)->stackStatus[(*head)->level][j - 1];

	t_tetriminos * el;
	el = *head;
		
		while (el)
		{
			if (el->c == letter)
				return el;
			el = el->next; 
		}
		return 0;
}


int qtyEatenEmptyCoords(int *curcoords, int *stack)
{
	int res;
	int i;

	res =0;
	i = 0;

	while (i <= 149)
	{
		if ((stack[i] != -5) && (stack[i + 1] != -5))
		{
			if ((curcoords[0] <= stack[i]) && (curcoords[1] < stack[i + 1]))
				res++;
			else if (curcoords[0] < stack[i])
				res++;
		}
		i += 2;
	}
	return res;
}

