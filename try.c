#include "fillit.h"


// (*head)->stackStatus
// coords[1]
// cur->c
// map[0]
// map[1]
// (*head)->level
//(*head)->used_empty_cell
//(*head)->empty_cell


//(int*)(*head)->stack_empty_coord


void rec_putFigOnMap(char ** map, int *coords, t_tetriminos *cur, t_tetriminos **head)
{
		
	int status = 1; 
	
	while (status == 1)
	{
		setFreeCell(coords, map);
		
		cur = findFigtoMap(head);
		
		if (!cur)
			status = 0;

		if (cur)
			status = putFigOnMap(map, coords, cur, head);

		if (status && cur)
		{
			(*head)->level++;
		}
	
	
	if ((*head)->level == (*head)->qty_fig)
	{
		
		displayMap(map); 
		exit(0);

	}

	
	if (status <= 0)
	{
		cur = findFigtoMap(head);
	

		if (!cur && (*head)->level == 0 && (*head)->stackStatus[0][(*head)->qty_fig - 1] != '\0' && (*head)->used_empty_cell == (*head)->empty_cell)
			{
				(*head)->empty_cell++;
				(*head)->used_empty_cell = 0;
				toZeroMap(head, map);
				toZeroStackCoord(head);
				delLastLevelFromSS(head);

			if ((((*head)->empty_cell + (*head)->qty_fig * 4) > (*head)->curmap_length * (*head)->curmap_length))
				{
					(*head)->empty_cell = 0;
					(*head)->used_empty_cell = 0;
					(*head)->curmap_length = (*head)->curmap_length + 1;
					resizeMap(&map, head);
				}
			}


		 else if (!cur && (*head)->empty_cell > 0 && (*head)->used_empty_cell < (*head)->empty_cell)
		{
			delLastLevelFromSS(head);
			setFreeCell(coords, map);
			setEmptyCell(coords, map);
		 	addCoordToStack(coords, head);
			(*head)->used_empty_cell++;
		}

		else if (!cur && (*head)->used_empty_cell == (*head)->empty_cell)
		{
			delLastLevelFromSS(head);
			(*head)->level--;
			deMapFig(map, findLastMappedFig(head));
			setFreeCell(coords, map);
			int qty = qtyEatenEmptyCoords(coords, (*head)->stack_empty_coord);
			deleteEatenEmptyCoordsFromMap(head, qty, map);
			deleteEatenEmptyCoordsFromStack(head, qty);
			(*head)->used_empty_cell = (*head)->used_empty_cell - qty;
		}

		rec_putFigOnMap(map, coords, cur, head);
	}
}
}



int main (int ac, char ** av)
{
	int coords [2] = {0, 0};
	static t_tetriminos *head = NULL;
	t_tetriminos *cur;

	if (ac != 2)
		return -5; // show usage

	int status;

	status = readFile(av[1], &head);
	cur = head;
	char ** map = createMap(minArrWidth(cur->qty_fig));

	rec_putFigOnMap(map, coords, cur, &head);

	return 0;
}
