#include "fillit.h"

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



int find_solution(char ** map, t_tetr *cur, t_tetr **head)
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
			if (canPutFigOnMap(map, r, c, cur, head))
			{
				PutFigOnMap(map, r, c, cur);
				status = find_solution(map, cur->next, head);
				if (status)
				{
					return 1;
				}
				deMapFig(map, cur, head);
			}
			++c;
		}
		++r;
	}
	return 0;
}

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
	return 1;
}


char **find_best_solution(t_tetr **head)
{
	
	char ** map = NULL;
	(*head)->curmap_length = find_min_sq_width((*head)->qty_fig);
	t_tetr * cur = (*head);

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

int readFile(char * av, t_tetr **head)
{
	int i = 0;
	int fd;
	int readsize;
	char buffer[21];
	ft_bzero(buffer, 21);

	fd = open(av, O_RDONLY);

	while (i <= 27)
	{
		readsize = read(fd, buffer, 20);
		if (!validate_figure_by_chars(buffer) || readsize != 20)
			return -1;		
		delete_nl(buffer);
		if (!validate_figure_by_connections(buffer))	
			return -1;		
		add_tetrimonos(buffer, head, i);
		i++;
		if (i == 27)
			return -1;		
		buffer[0] = '\0';
		readsize = read(fd, buffer, 1);		
		if (readsize == 0)
		{	
			(*head)->qty_fig = i;
			(*head)->curmap_length = find_min_sq_width((*head)->qty_fig);
			return 5;
		}
		else if (buffer[0] != '\n' || readsize < 0)
			return -1;		
	}
	return 5;
}

#include <fcntl.h>
	
int main (int ac, char ** av)
{
	t_tetr *head = NULL;

	if (ac != 2)
		return -5; // show usage

	int status;

	status = readFile(av[1], &head);
	if (status == -1)
	{
		write(1, "error\n", 6);
		cleanup(&head);
		system("leaks a.out");
	
		exit(0);
	}
	char ** map = find_best_solution(&head);

	displayMap(map, &head);
	head->curmap_length++; 
	destroy_map(map, &head);

   system("leaks a.out");
	
	return 0;
}

