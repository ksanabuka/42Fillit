
#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

// INPUT       char * "..#. ..## ...# ...."
// OPUTUP      int * "2,0, 2,1, 3,1, 3,2"

int	*make_fig_coordinates(char *str)
{
	int		*xy_arr;
	int		i;
	int		j;
	char	*x;
	char	*y;

	xy_arr = (int *)malloc(sizeof(int) * 8);
	x = "0123012301230123";
	y = "0000111122223333";
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			xy_arr[j] = x[i] - 48;
			j++;
			xy_arr[j] = y[i] - 48;
			j++;
		}
		i++;
	}
	convert_coordinates(&xy_arr);
	return (xy_arr);
}


void	convert_coordinates(int **arr)
{
	int start_x;
	int start_y;
	int k;

	k = 2;
	start_x = (*arr)[0];
	start_y = (*arr)[1];
	while (k < 8)
	{
		(*arr)[k] = (*arr)[k] - start_x;
		k++;
		(*arr)[k] = (*arr)[k] - start_y;
		k++;
	}
	(*arr)[0] = 0;
	(*arr)[1] = 0;
}



