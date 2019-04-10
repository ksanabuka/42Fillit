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
	int i = 0;
	
	char *tmp = ft_strdup((*head)->stackStatus[0]);
	(*head)->stackStatus[0][0] = figure->c;
	(*head)->stackStatus[0][1] = '\0';
	ft_strcat((*head)->stackStatus[0], tmp);
	free(tmp);	
}

void delLastLevelFromSS(t_tetriminos ** head, int level)
{
	int j = 0; 
	while ((*head)->stackStatus[level][j] != '\0')
	{
		(*head)->stackStatus[level][j] = '\0';
		j++;
	}
}

int isMapped(t_tetriminos ** head, t_tetriminos * figure)
{

	int i = 0; 
	int j;
	int c = 0;

	while (i <= (*head)->level);
	{
		j = 0;
		while ((*head)->stackStatus[i][j] != '\0')
			j++;
		if ((*head)->stackStatus[i][j] == '\0' && j > 0 && (*head)->stackStatus[i][j - 1] == figure->c)
			return 1; 
		i++;
	}
	return 0;
}

