#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>

typedef struct		s_tetriminos
{
	char			*buffer;
	struct s_tetriminos	*next;
}					t_tetriminos;

void add_tetrimonos(char *buffer, t_tetriminos **head)
{
	t_tetriminos * el;

	el = (t_tetriminos *)malloc(sizeof(t_tetriminos));
	if (!el)
		return  ;
	if (!head)
		return  ;
	
	el->buffer = ft_strdup(buffer);
	if (!el->buffer)
	{
		free(el);
		return  ;
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
}

int main(void)
{
	t_tetriminos **head = NULL; 

	char buffer1[17] = "mama";
	char buffer2[17] = "HURRAAA";
	char buffer3[17] = "i love papulya";
	
	head = (t_tetriminos**)malloc(sizeof(t_tetriminos*));

	add_tetrimonos(buffer1, head);
	add_tetrimonos(buffer2, head);
	add_tetrimonos(buffer3, head);

	printf("1 -	%s\n 2 -	%s\n 2 -	%s\n ", (*head)->buffer, (*head)->next->buffer, (*head)->next->next->buffer);

}
