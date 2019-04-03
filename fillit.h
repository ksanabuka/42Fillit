

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
	int					c;
	int 				arr [6];
	char				*buffer;
	struct s_tetriminos	*next;
}						t_tetriminos;

int readFile(char * av, t_tetriminos **head);
