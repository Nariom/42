/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 17:49:49 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/07 18:38:57 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int		ft_word(int *i, char *s, int dir)
{
	int		j;

	j = i[0] - 3;
	if (dir == -1)
	{
		while (j > 0 && (s[j] == ' ' || s[j] == '\t'))
			j--;
		while (j > 0 && s[j] != ' ' && s[j] != '\t')
			j--;
	}
	else
	{
		while (j < i[1] - 3 && (s[j] == ' ' || s[j] == '\t'))
			j++;
		while (j < i[1] - 3 && s[j] != ' ' && s[j] != '\t')
			j++;
	}
	return (j);
}

void	ft_send(int *i, t_lst **l, char **s, char **env)
{
	ft_putchar('\n');
	if (s && s[1])
	{
		ft_add(l, ft_new(s[1]));
		i[5]++;
		ft_sh(s[1], env);
	}
	ft_strdel(s);
	ft_strdel(s + 1);
	ft_putstr("$> ");
	i[0] = 3;
	i[1] = 3;
	i[4] = 0;
}

void	ft_move(int *cur, int pos)
{
	tputs(tgoto(tgetstr("ch", NULL), 0, pos), 1, ft_outc);
	*cur = pos;
}

void	ft_delete(int *cur, int *len, char **s)
{
	ft_remove(*cur - 3, *len - 3, s);
	ft_move(cur, *cur - 1);
	tputs(tgetstr("dc", NULL), 1, ft_outc);
	(*len)--;
}

void	ft_put(int *cur, int *len, char c, char **s)
{
	ft_save(*cur - 3, *len - 3, c, s);
	ft_putchar(c);
	(*cur)++;
	(*len)++;
}
