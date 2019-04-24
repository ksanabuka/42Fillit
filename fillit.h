

#include <fcntl.h>

# include <stdlib.h>
# include <unistd.h>
#include "libft/libft.h"
#include <stdlib.h>
#include "libft/libft.h"

typedef struct			s_tetriminos
{
	int					c;
	int 				*arr;
	int 				qty_fig;
	int 				curmap_length;
	struct s_tetriminos	*next;
}
						t_tetr;


t_tetr	*add_tetrimonos(char *buffer, t_tetr **head, int i);
void	write_to_tetrimono(char *buffer, int i, t_tetr **el);
int cleanup(t_tetr ** head);
int	delete_nl(char *str);
int		validate_figure_by_connections(char *s);
int		validate_figure_by_chars(char *s);
int readFile(char * av, t_tetr **head);

int find_min_sq_width(int numFigs);
int find_solution(char ** map, t_tetr *cur, t_tetr **head);
int destroy_map(char ** map, t_tetr **head);
char **find_best_solution(t_tetr **head);

char **createMap(int length);
int canPutFigOnMap(char ** map,  int r_0,  int c_0, t_tetr * figure, t_tetr ** head);
void PutFigOnMap(char ** map,  int r_0,  int c_0, t_tetr * figure);
void deMapFig(char ** map, t_tetr * figure, t_tetr ** head);
void displayMap(char ** map, t_tetr ** head);

int	*make_fig_coordinates(char *str);
void	convert_coordinates(int **arr);


