
#include "fillit.h"

t_tetriminos * add_tetrimonos(char *buffer, t_tetriminos **head, int i)
{
	t_tetriminos * el;

	el = (t_tetriminos *)malloc(sizeof(t_tetriminos));
	if (!el)
		return (0);
	if (!head)
		return (0);
	el->c = i + 65;
	el->buffer = ft_strdup(buffer);
	el->status = 0;
	el->arr = make_fig_coordinates(el->buffer);

	if (!el->buffer)
	{
		free(el);
		return (0);
	}
	if (!*head)
	{
		el->next = NULL;
	}
	else
	{
		el->next = *head;
	}
	*head = el;
	return (el);
}

int cleanup(t_tetriminos ** head)
{
	t_tetriminos * el;
	el = *head;
	if (el)
	{
		if (el->next)
			cleanup(&el->next);
		free(el->arr);
		free(el->buffer);
		free(el);
		*head = NULL;
	}
	return 1;
}


// int main(void)
// {
// 	t_tetriminos *head = NULL; 
// 	t_tetriminos *el = NULL; 

// 	char buffer1[17] = "mama";
// 	char buffer2[17] = "HURRAAA";
// 	char buffer3[17] = "i love papulya";
// 	int status; 
// 	el = add_tetrimonos(buffer1, &head);
// 	el = add_tetrimonos(buffer2, &head);
// 	el = add_tetrimonos(buffer3, &head);

// 	el = head; 
// 	while (el)
// 		{
// 			printf("%s\n", (el)->buffer);
// 			el = (el)->next;
// 		}	
// 	el = head;
// 	status = cleanup(&head);

// 	// if (el)
// 	// {
// 	// 	while (el)
// 	// 		{
// 	// 			printf("%s\n", (el)->buffer);
// 	// 			el = (el)->next;
// 	// 		}	
// 	// }
// 	//system("leaks a.out");
// 	return 0;

// }


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

// int main (void)
// {
// 	char  str [25] = "...#\n...#\n...#\n...#\n";

// 	deletenl(str);
// 	printf("%s\n", str);

// }

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

int MinArrWidth(int qtyFig)
{
	int arr [11] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121};
	int sq = qtyFig * 4;
	int i = 0;
	if (sq <= 16)
		return 4;

	while (i < 11)
	{
		if (sq == arr[i])
			return i + 1; 

		else if (i != 10 && sq > arr[i] && sq < arr[i + 1])
		{
			return (i + 1 + 1);
		}
		else if (i == 10 && sq > 100 && sq < 121)
			return 11;
		i++;
	}
	return i;
}

// int main (void)
// {
// 	int tab[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
// 	int i = 0;
// 	while (i < 26)
// 	{
// 		printf("for	%d figs - sq side length is -	%d\n", i + 1, MinArrWidth(tab[i]));
// 		i++;
// 	}
// 	return 0;
// }



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

int readFile(char * av, t_tetriminos **head)
{
	int i = 0;
	//int flag = 0;

	int fd;
	//int status = 0;
	int readsize;
	char buffer[21];
	ft_bzero(buffer, 21);
	t_tetriminos *el;
	int status;

	fd = open(av, O_RDONLY);

	while (i <= 27)
	{
		readsize = read(fd, buffer, 20);
		if (readsize != 20 || !validate_figure_by_chars(buffer))
		{	
			status = cleanup(head);
			return -1;
		}
		deletenl(buffer);
		if (!validateFigureByConnections(buffer))	
		{			
			status = cleanup(head);
			return -1;		
		}
		el = add_tetrimonos(buffer, head, i);
		if (!(el))
		{			
			status = cleanup(head);
			return -1;		
		}
		i++;
		if (i == 27)
		{			
			status = cleanup(head);
			return -1;		
		}
		buffer[0] = '\0';
		readsize = read(fd, buffer, 1);		
		if (readsize == 0)
		{		
			// while (*head)
			// {
			// 	printf("%c	%s\n", (*head)->c,(*head)->buffer);
				
			// 	printf("%d ", (*head)->arr[0]);
			// 	printf("%d ", (*head)->arr[1]);
			// 	printf("%d ", (*head)->arr[2]);
			// 	printf("%d ", (*head)->arr[3]);
			// 	printf("%d ", (*head)->arr[4]);
			// 	printf("%d ", (*head)->arr[5]);
			// 	printf("%d ", (*head)->arr[6]);
			// 	printf("%d ", (*head)->arr[7]);

			// 	*head = (*head)->next;
			// }	
			return 5;
		}
		else if (buffer[0] != '\n' || readsize < 0)
		{			
			status = cleanup(head);
			return -1;		
		}
	}
			return 5;
}


// int main(int ac, char ** av)
// {
// 	t_tetriminos *head = NULL;

// 	if (ac != 2)
// 		return -5; // show usage

// 	int status;

// 	status = readFile(av[1], &head);
	
// 	if (status == -1)
// 		printf("Not valid\n");
// 	else 
// 		printf("Valid\n");

// 	return 0;
// }







