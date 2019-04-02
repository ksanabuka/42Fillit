//#include "validation.c"
#include <stdio.h>
#include "libft/libft.h"

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




int main (void)
{
	createMap(7);
	return 0;
}