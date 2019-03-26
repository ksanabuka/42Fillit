#include <stdio.h>

int validateFigureByConnections(char *s)
{
	int i = 0;
	int count = 0;

	while (s[i])
	{
		if ((i - 1 >= 0) && s[i-1] == '#' && s[i] == '#')
			count++;
		if ((i - 4 >= 0) && s[i-4] == '#' && s[i] == '#')
			count++;
		if ((i + 1 <= 15) && s[i+1] == '#' && s[i] == '#')
			count++;
		if ((i + 4 <= 15) && s[i+4] == '#' && s[i] == '#')
			count++;
		i++;
	}
	if (count == 6 || count == 8)
		return 1;
	else 
		return 0;
}

int validate_figure_by_chars(char *s)
{
	//check for that string consists only of '.' '#' && has exactly 4 '#'s. 
	int countHash = 0;
	int i = 0;
	while (s[i])
	{
		if ((s[i] != '.' && s[i] != '#' )|| countHash > 4)
			return (0);
		else if (s[i] == '#')
		{
			countHash++;
			i++;
		}
		else 
			i++;
	}
	if (countHash != 4)
		return (0);
	else 
		return (1);
}

// int main (void)
// {
// 	char *s1 = "..,#...#...#...#";
// 	char *s2 = "............####";
// 	char *s3 = ".###...#........";
// 	char *s4 = "......##.##.....";
// 	char *s5 = "......##.##....#";
// 	char *s6 = "......##.##....#";
// 	char *s7 = "#..#........#..#";
// 	char *s8 = "##..........#..#";

// 	printf("1:	%d - %d", validateFigureByConnections(s1), validate_figure_by_chars(s1));
// 	printf("2:	%d - %d", validateFigureByConnections(s2), validate_figure_by_chars(s2));
// 	printf("3:	%d - %d", validateFigureByConnections(s3), validate_figure_by_chars(s3));
// 	printf("4:	%d - %d", validateFigureByConnections(s4), validate_figure_by_chars(s4));
// 	printf("5:	%d - %d", validateFigureByConnections(s5), validate_figure_by_chars(s5));
// 	printf("6:	%d - %d", validateFigureByConnections(s6), validate_figure_by_chars(s6));
// 	printf("7:	%d - %d", validateFigureByConnections(s7), validate_figure_by_chars(s7));
// 	printf("8:	%d - %d", validateFigureByConnections(s8), validate_figure_by_chars(s8));

// 	return 0;
// }

// one figure
// 	4 x (read 4 char (. || #) \n)
// 	#  == 4

// \n (not EOF)
// figure++;



