/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:58:07 by iiskakov          #+#    #+#             */
/*   Updated: 2019/04/25 13:44:16 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		*add_tetrimonos(char *buffer, t_tetr **head, int i)
{
	t_tetr	*el;
	t_tetr	*tmp;

	el = (t_tetr *)malloc(sizeof(t_tetr));
	if ((!el) || (!head))
		return (0);
	write_to_tetrimono(buffer, i, &el);
	if (!*head)
		(*head) = el;
	else
	{
		tmp = (*head);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = el;
	}
	return (el);
}

int			cleanup(t_tetr **head)
{
	t_tetr	*el;

	el = *head;
	if (el)
	{
		if (el->next)
			cleanup(&el->next);
		free(el->arr);
		free(el);
		*head = NULL;
	}
	return (1);
}

int			delete_nl(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		if (*s == '\n' && *(s + 1))
		{
			ft_memmove(s, s + 1, ft_strlen(s));
			s++;
		}
		if (*s == '\n' && !(*(s + 1)))
		{
			*s = '\0';
			return (-1);
		}
		s++;
	}
	return (0);
}

int			validate_figure_by_connections(char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i >= 1) && s[i - 1] == '#' && s[i] == '#')
			count++;
		if ((i >= 4) && s[i - 4] == '#' && s[i] == '#')
			count++;
		if ((i <= 14) && s[i + 1] == '#' && s[i] == '#')
			count++;
		if ((i <= 11) && s[i + 4] == '#' && s[i] == '#')
			count++;
		i++;
	}
	return (count == 6 || count == 8);
}

int			validate_figure_by_chars(char *s)
{
	int		count_hash;
	int		count_dots;
	int		count_nl;
	int		i;

	count_hash = 0;
	count_dots = 0;
	count_nl = 0;
	i = 0;
	if (s[4] != '\n' || s[9] != '\n' || s[14] != '\n' || s[19] != '\n')
		return (0);
	while (s[i])
	{
		if (s[i] == '#')
			count_hash++;
		else if (s[i] == '.')
			count_dots++;
		else if (s[i] == '\n')
			count_nl++;
		else
			return (0);
		i++;
	}
	return (count_hash == 4 && count_dots == 12 && count_nl == 4);
}
