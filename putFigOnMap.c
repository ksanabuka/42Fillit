#include "fillit.h"

char **createMap(int length)
{
	char ** res = (char**)malloc(sizeof(char*) * (length + 1));
	res[length] = NULL;
	int i = 0;
	while (i < length)
	{
		res[i] = (char*)malloc(sizeof(char) * (length + 1));
		ft_memset(res[i], 46, length);
		res[i][length] = '\0';
		printf("%d - %s\n", i, res[i]);
		i++;
	}
	return res;
}



int putFigOnMap(char ** map, int 0_x, int 0_y, t_tetriminos * figure)
{
	int j = 0;
	int i = 0;
	int arr[8] = {1,0, 1,1, 2,1};

	char block2 = map[0_y + arr[1]][0_x + arr[0]];
	char block3 = map[0_y + arr[3]][0_x + arr[2]];
	char block4 = map[0_y + arr[5]][0_x + arr[4]];


	char ** map = createMap(4);
	if (map[0_y][0_x] == '.') && map[0_y + arr[0][0_x + arr[1]] ]



	 

}


int main (void)
{
	createMap(7);
	return 0;
}