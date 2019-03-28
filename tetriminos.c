
typedef struct		s_tetriminos
{
	char			*buffer;
	struct s_mylist	*next;
}					t_tetriminos;


t_tetriminos **add_tetrimonos(char *buffer, t_tetriminos **head)
{
	t_tetriminos * el;

	el = (t_tetriminos *)malloc(sizeof(t_tetriminos));
	if (!el)
		return (0);
	if (!head)
		return (0);
	
	el->buffer = ft_strdub(buffer);
	if (!el->buffer)
	{
		free(el);
		return (0)
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
	return head ; 
}



