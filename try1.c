#include "fillit.h"

int	find_solution(char **map, t_tetr *cur, t_tetr **head)
{	
	int 	r;
	int 	c;
	int 	status;

	if (!cur)
		return (1);
	r = 0;	
	while (r < (*head)->curmap_length)
	{
		c = 0;
		while (c < (*head)->curmap_length)
		{
			if (can_put_fig_on_map(map, r, c, cur, head))
			{
				put_fig_on_map(map, r, c, cur);
				status = find_solution(map, cur->next, head);
				if (status)
				{
					return 1;
				}
				demap_fig(map, cur, head);
			}
			++c;
		}
		++r;
	}
	return (0);
}

int		fig_validation(int i, int readsize, char *buffer)
{
	if (!validate_figure_by_chars(buffer) || readsize != 20)
		return 0;		
	delete_nl(buffer);
	if (!validate_figure_by_connections(buffer) || i + 1 == 27)	
		return 0;
	return 1; 		
}

int		set_qtyFig_MinSq(int i, t_tetr **head)
{
	(*head)->qty_fig = i;
	(*head)->curmap_length = find_min_sq_width((*head)->qty_fig);
	return 5;
}

int		readFile(char * av, t_tetr **head)
{
	int 	i;
	int 	fd;
	int 	readsize;
	char	buffer[21];
	
	i = 0;
	ft_bzero(buffer, 21);
	fd = open(av, O_RDONLY);
	while (i <= 27)
	{
		readsize = read(fd, buffer, 20);
		if (!fig_validation(i, readsize, buffer))
			return (-1); 
		add_tetrimonos(buffer, head, i);
		i++;
		buffer[0] = '\0';
		readsize = read(fd, buffer, 1);		
		if (readsize == 0)
			return (set_qtyFig_MinSq(i, head));
		else if (buffer[0] != '\n' || readsize < 0)
			return (-1);		
	}
	return (5);
}
	
int 	main(int ac, char **av)
{
	int 	status;

	t_tetr *head = NULL;
	if (ac != 2)
		return (-5);
	status = readFile(av[1], &head);
	if (status == -1)
	{
		write(1, "error\n", 6);
		cleanup(&head);	
		exit(0);
	}
	char ** map = find_best_solution(&head);

	display_map(map, &head);
	head->curmap_length++; 
	destroy_map(map, &head);	
	return (0);
}
