#include "fillit.h"

int destroy_map(char ** map, t_tetr **head)
{
	int i = 0;
	if (!map)
		return 1;
	while (i <  ((*head)->curmap_length) - 1)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (1);
}

int find_min_sq_width(int numFigs)
{
	int arr [12] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121};
	int sq = numFigs * 4;
	int i = 0;
	
	while (i < 12)   
	{
		if (sq <= arr[i])
			return i;
		++i;
	}
	return i;
}

void display_map(char **map, t_tetr **head)
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

void	write_to_tetrimono(char *buffer, int i, t_tetr **el)
{
	(*el)->c = i + 65;
	(*el)->qty_fig = 0;
	(*el)->arr = make_fig_coordinates(buffer);
	(*el)->next = NULL;
}

char **find_best_solution(t_tetr **head)
{
	
	char **map;
	(*head)->curmap_length = find_min_sq_width((*head)->qty_fig);
	t_tetr *cur = (*head);
	map = NULL;

	while (1)
	{
		destroy_map(map, head);
		map = create_map((*head)->curmap_length);
		int status = find_solution(map, cur, head);
		if (status)
			return map;
		(*head)->curmap_length++;
	}
	return (NULL);
}
