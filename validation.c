

// read20 ->check20chars ->delNL ->checkconnections
// 		if (20) -OK
// 		else  -> 0; 
// read1 -> if (NL) -> read20must
// 		 if (0) reaturn 1;

 


#include <stdio.h>
#include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include "libft/libft.h"




void deletenl(char *str)
{
	char * s;

	s = str;

	while (*s)
	{
		if (*s == '\n' && *(s + 1))
		{
			ft_memmove(s, s + 1, ft_strlen(s));
			s++;
		}
		if (*s == '\n' && !(*(s + 1)))
		{
			*s = '\0';
			return ;
		}
		s++;
	}

	return ;
}

int main (void)
{
	char  str [25] = "...#\n...#\n...#\n...#\n";

	deletenl(str);
	printf("%s\n", str);

}

int validateFigureByConnections(char *s)
{
	int i = 0;
	int count = 0;

	while (s[i])
	{
		if ((i >= 1) && s[i-1] == '#' && s[i] == '#')
			count++;
		if ((i >= 4) && s[i-4] == '#' && s[i] == '#')
			count++;
		if ((i <= 14) && s[i+1] == '#' && s[i] == '#')
			count++;
		if ((i <= 11) && s[i+4] == '#' && s[i] == '#')
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
	int countDots = 0;
	int countNl = 0;

	int i = 0;

	if (s[4] != '\n' || s[9] != '\n' || s[14] != '\n' || s[19] != '\n')
		return (0);

	while (s[i])
	{

		if (s[i] == '#')
		{
			countHash++;
			i++;
		}
		else if (s[i] == '.')
		{
			countDots++;
			i++;
		}
		else if (s[i] == '\n')
		{
			countNl++;
			i++;
		}
		else
			return 0;
	}

	if (countHash != 4 || countDots != 12 || countNl != 4)
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

int readFile(char * av)
{
	int i = 0;
	//int flag = 0;

	int fd;
	//int status = 0;
	int readsize;
	char buffer[21];
	ft_bzero(buffer, 21);


	fd = open(av, O_RDONLY);

	while (i <= 27)
	{
		

		readsize = read(fd, buffer, 20);
		printf("before deletion 	i = %d\n%s\n", i, buffer);

		if (readsize != 20 || !validate_figure_by_chars(buffer))
		{			
			return -1;
		}
		deletenl(buffer);
		printf("after deletion 	i = %d\n%s\n", i, buffer);

		if (!validateFigureByConnections(buffer))
			
		{			
			return -1;
		}
		//add_tostructure(buffer;)
		i++;
		if (i == 27)
			return -1;

		buffer[0] = '\0';

		readsize = read(fd, buffer, 1);
		
		if (readsize == 0)
		{			
			return 5;
		}
		else if (buffer[0] != '\n' || readsize < 0)
		{			
			return -1;
		}
	}
	return 1;
}


int main(int ac, char ** av)
{
	if (ac != 2)
		return -5; // show usage

	int status;

	status = readFile(av[1]);
	
	if (status == -1)
		printf("Not valid\n");
	else 
		printf("Valid\n");

	return 0;
}







