

#include <fcntl.h>

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include "libft/libft.h"

#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>

typedef struct			s_tetriminos
{
	int 				status;
	int					c;
	int 				*arr;
	int 				wasAt00;
	int 				qty_fig;
	char				*buffer;
	struct s_tetriminos	*next;
}						t_tetriminos;

int readFile(char * av, t_tetriminos **head);
int *make_fig_coordinates(char *str);

