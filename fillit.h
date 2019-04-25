# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"


typedef struct			s_tetriminos
{
	int					c;
	int 				*arr;
	int 				qty_fig;
	int 				curmap_length;
	struct s_tetriminos	*next;
}
						t_tetr;

void	write_to_tetrimono(char *buffer, int i, t_tetr **el);
int 	set_qtyfig_minsq(int i, t_tetr **head);
int		*make_fig_coordinates(char *str);
void	convert_coordinates(int **arr);
int 	find_min_sq_width(int numFigs);
char	**create_map(int length);
int		can_put_fig_on_map(char **map, int r_0,  int c_0, t_tetr *figure, t_tetr **head);
void 	put_fig_on_map(char ** ap,  int r_0,  int c_0, t_tetr *figure);
void 	demap_fig(char **map, t_tetr *figure, t_tetr **head);
void 	display_map(char **map, t_tetr **head);
int		delete_nl(char *str);
int		validate_figure_by_connections(char *s);
int		validate_figure_by_chars(char *s);
int 	fig_validation(int i, int readsize, char *buffer);
int 	cleanup(t_tetr ** head);
int 	destroy_map(char ** map, t_tetr **head);
int 	find_solution(char ** map, t_tetr *cur, t_tetr **head);
char 	**find_best_solution(t_tetr **head);
int 	readfile(char * av, t_tetr **head);
t_tetr	*add_tetrimonos(char *buffer, t_tetr **head, int i);
