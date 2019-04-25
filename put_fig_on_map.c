/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fig_on_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:18:12 by iiskakov          #+#    #+#             */
/*   Updated: 2019/04/25 13:19:39 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int length)
{
	char	**res;
	int		i;

	res = (char**)malloc(sizeof(char*) * (length));
	i = 0;
	while (i < length)
	{
		res[i] = (char*)malloc(sizeof(char) * (length + 1));
		ft_memset(res[i], 46, length);
		res[i][length] = '\0';
		i++;
	}
	return (res);
}
int		can_put_fig_on_map(char **map, int r_0,  int c_0, t_tetr *figure, t_tetr **head)
{
	int		j;
	int		length;

	j = 0;
	length = (*head)->curmap_length - 1;
	if ((r_0 + figure->arr[1] <= length) && (r_0 + figure->arr[1] >= 0) && \
		(c_0 + figure->arr[0] <= length) && (c_0 + figure->arr[0] >= 0) && \
		(r_0 + figure->arr[3] <= length) && (r_0 + figure->arr[3] >= 0) && \
		(c_0 + figure->arr[2] <= length) && (c_0 + figure->arr[2] >= 0) && \
		(r_0 + figure->arr[5] <= length) && (r_0 + figure->arr[5] >= 0) && \
		(c_0 + figure->arr[4] <= length) && (c_0 + figure->arr[4] >= 0) && \
		(r_0 + figure->arr[7] <= length) && (r_0 + figure->arr[7] >= 0) && \
		(c_0 + figure->arr[6] <= length) && (c_0 + figure->arr[6] >= 0))
	{
		if ((map[r_0 + figure->arr[1]][c_0 + figure->arr[0]] == '.') && \
			(map[r_0 + figure->arr[3]][c_0 + figure->arr[2]] == '.') && \
			(map[r_0 + figure->arr[5]][c_0 + figure->arr[4]] == '.') && \
			(map[r_0 + figure->arr[7]][c_0 + figure->arr[6]] == '.'))
			return (1);
		else
			return (0);
	}
	else 
		return (0);
}

void 	put_fig_on_map(char **map, int r_0, int c_0, t_tetr *figure)
{
	map[r_0][c_0] = figure->c;
	map[r_0 + figure->arr[3]][c_0 + figure->arr[2]] = figure->c;
	map[r_0 + figure->arr[5]][c_0 + figure->arr[4]] = figure->c;
	map[r_0 + figure->arr[7]][c_0 + figure->arr[6]] = figure->c;
}

void 	demap_fig(char **map, t_tetr *figure, t_tetr **head)
{
	int 	i;
	char 	*tmp;

	i = 0;
	while (i < (*head)->curmap_length)
	{
		while (((tmp = ft_strchr(map[i], figure->c)) != NULL))
			*tmp = '.';
		i++;
	}
}
