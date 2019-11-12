/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 11:03:11 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/07 18:21:56 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_remove(int cur, int len, char **s)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = (char *) malloc(len * sizeof(*tmp));
	i = 0;
	j = 0;
	while (j < len)
	{
		if (j == cur - 1)
			j++;
		else
			tmp[i++] = (*s)[j++];
	}
	tmp[i] = 0;
	ft_strdel(s);
	*s = tmp;
}

void	ft_save(int cur, int len, char c, char **s)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = (char *) malloc((len + 2) * sizeof(*tmp));
	i = 0;
	j = 0;
	while (i < len + 1)
	{
		if (i == cur)
			tmp[i++] = c;
		else
			tmp[i++] = (*s)[j++];
	}
	tmp[i] = 0;
	ft_strdel(s);
	*s = tmp;
}

void	ft_cut(int *i, char **s, char **t, char c)
{
	ft_strdel(t);
	if (c == 7 && i[0] > 3)
	{
		*t = ft_strsub(*s, 0, i[0] - 3);
		while (i[0] > 3)
			ft_delete(i, i + 1, s);
	}
	if (c == 8 && i[0] < i[1])
	{
		*t = ft_strsub(*s, i[0] - 3, i[1] - i[0]);
		while (i[0] < i[1])
		{
			ft_move(i, i[0] + 1);
			ft_delete(i, i + 1, s);
		}
	}
}

void	ft_cutw(int *i, char **s, char **t, char c)
{
	int		dir;
	int		swap;
	int		j;
	int		k;

	ft_strdel(t);
	if ((c == 2 && i[0] > 3) || (c == 14 && i[0] < i[1]))
	{
		dir = (c == 2) ? -1 : 1;
		j = ft_word(i, *s, dir);
		swap = j + 3;
		j = (dir == 1) ? i[0] - 3 : j;
		if (dir == 1)
			ft_move(i, swap);
		while ((*s)[j] == ' ' || (*s)[j] == '\t')
			j += 1;
		while ((*s)[i[0] - 4] == ' ' || (*s)[i[0] - 4] == '\t')
			ft_move(i, i[0] - 1);
		k = i[0];
		*t = ft_strsub(*s, j, i[0] - 3 - j);
		while (--k >= j + 3)
			ft_delete(i, i + 1, s);
	}
}

void	ft_paste(int *i, char **s, char *t)
{
	int		j;

	ft_putstr(t);
	j = 0;
	while (t && t[j])
	{
		ft_save(i[0] - 3, i[1] - 3, t[j], s);
		i[0]++;
		i[1]++;
		j++;
	}
}
