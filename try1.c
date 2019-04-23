//
//  solver.c
//  fillit
//
//  Created by Oksana Buksha on 4/20/19.
//  Copyright © 2019 Oksana Buksha. All rights reserved.
//
#include "fillit.h"

unsigned int find_min_sq_width(unsigned int numFigs)
{
	unsigned int arr [12] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121};
	unsigned int sq = numFigs * 4;
	unsigned int i = 0;
	
	while (i < 12)   
	{
		if (sq <= arr[i])
			return i;
		++i;
	}
	return i;
}


int find_solution(char ** map, t_tetriminos *cur, t_tetriminos **head)
{	
	int r;
	int c;
	int status;
	
	if (!cur)
	{
		return 1;
	}
	
	r = 0;	
	while (r < (*head)->curmap_length)
	{
		c = 0;
		while (c < (*head)->curmap_length)      
		{
			if (canPutFigOnMap(map, r, c, cur))
			{
				putFigOnMap(map, r, c, cur);
				status = find_solution(map, cur->next, head);
				if (status)
				{
					return 1;
				}
				deMapFig(map, cur);
			}
			++c;
		}
		++r;
	}
	return 0;
}

int destroy_map(char ** map, t_tetriminos **head)
{
	int i = 0;
	if (!map)
		return 1;
	while (i <  ((*head)->curmap_length))
	{
		free(map[i]);
		i++;
	}
	return 1;
}


char **find_best_solution(t_tetriminos **head)
{
	
	char ** map = NULL;
	(*head)->curmap_length = find_min_sq_width((*head)->qty_fig);
	t_tetriminos * cur = (*head);

	while (1)
	{
		destroy_map(map, head);
		map = createMap((*head)->curmap_length);
		int status = find_solution(map, cur, head);
		if (status)
		{
			return map;
		}

		(*head)->curmap_length++;
	}
	return NULL;
}

void printMap(char ** map, t_tetriminos **head)
{
	int i = 0;
	while (i < (*head)->curmap_length)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int main (int ac, char ** av)
{
	t_tetriminos *head = NULL;

	if (ac != 2)
		return -5; // show usage

	int status;

	status = readFile(av[1], &head);
	char ** map = find_best_solution(&head);

	printMap(map, &head);

	return 0;
}

