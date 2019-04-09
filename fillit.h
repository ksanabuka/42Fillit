

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
	int 				*stackMappedFigs;
	int 				empty_cell; 
	int 				qty_fig;
	int 				curmap_length;
	char				*buffer;
	struct s_tetriminos	*next;
}						t_tetriminos;


int readFile(char * av, t_tetriminos **head);
int *make_fig_coordinates(char *str);
void convert_coordinates(int **arr);
t_tetriminos * add_tetrimonos(char *buffer, t_tetriminos **head, int i);
void setQtyFig(int i, t_tetriminos ** head);
int cleanup(t_tetriminos ** head);
void deletenl(char *str);
int validateFigureByConnections(char *s);
int validate_figure_by_chars(char *s);
int MinArrWidth(int qtyFig);
int readFile(char * av, t_tetriminos **head);
char **createMap(int length);
void freemap(char ** map);
int  setFigStatus(int status, int curStatus, t_tetriminos **head);
int countStatus(int status, t_tetriminos **head);
t_tetriminos *findFigtoMap(t_tetriminos **head);
int putFigOnMap(char ** map, int r_0, int c_0, t_tetriminos * figure);
void deMapFig(char ** map, t_tetriminos * figure);
void mark_cur_fig_minus(t_tetriminos * figure);
void displayMap(char ** map);
int WasAt00(t_tetriminos ** head);
int 	setFreeCell(int * coords, char ** map);
void rec_putFigOnMap(char ** map, int coords [2], t_tetriminos *cur, t_tetriminos **head, int empty_cell);



