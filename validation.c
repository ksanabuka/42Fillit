
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
	el->wasAt00 = 0;
	el->qty_fig = 0;
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

void setQtyFig(int i, t_tetriminos ** head)
{
	t_tetriminos * el;
	el = *head;

	while(el)
	{
		el->qty_fig = i;
		el = el->next;
	}
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
			setQtyFig(i, head);
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






