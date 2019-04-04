
#include <stdlib.h>
#include <stdio.h>
// INPUT       char * "..#. ..## ...# ...."
// OPUTUP      int * "2,0, 2,1, 3,1, 3,2"

void convert_coordinates(int **arr)
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

int *make_fig_coordinates(char *str)
{
	int *xy_arr;
	int i;
	int j;
	char *x;
	char *y;

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
	// i = 0;
	// printf("%s\n", "Relative coordinates array\n");
	// while (i < 8)
	// {
	// 	printf("%d\n", xy_arr[i]);
	// 	i++;
	// }
	convert_coordinates(&xy_arr);
	// i = 0;
	// printf("%s\n", "-------------------------\n");
	// printf("%s\n", "Absolute coordinates array\n");
	// while (i < 8)
	// {
	// 	printf("%d\n", xy_arr[i]);
	// 	i++;
	// }
	return(xy_arr);
}



// int main()
// {
// 	char *s1 = "..,#...#...#...#";
// 	char *s2 = "............####";
// 	char *s3 = ".###...#........";
// 	char *s4 = "......##.##.....";
// 	char *s5 = "......##.##....#";
// 	char *s6 = "......##.##....#";
// 	char *s7 = "#..#........#..#";
// 	char *s8 = "##..........#..#";
// 	make_fig_coordinates(s1);
// 	make_fig_coordinates(s2);
// 	make_fig_coordinates(s3);
// 	make_fig_coordinates(s4);
// 	make_fig_coordinates(s5);
// 	make_fig_coordinates(s6);
// 	make_fig_coordinates(s7);
// 	make_fig_coordinates(s8);

// 	return 0;
// }
