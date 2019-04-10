#include "fillit.h"

void rec_putFigOnMap(char ** map, int *coords, t_tetriminos *cur, t_tetriminos **head)
{

	int status = 1; 
	
	while (status == 1)
	{
		setFreeCell(coords, map);
		cur = findFigtoMap(head);
		status = putFigOnMap(map, coords[0], coords[1], cur);

		if (status)
		{
			(*head)->level++;
		}
	

	}



}


//demap 0-level is not allowed --> means we need to resize map; 