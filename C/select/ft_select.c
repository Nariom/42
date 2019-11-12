/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:00:30 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/09 21:02:15 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_arrow(char c, t_slct *slct)
{
	if (c == 65)
	{
		slct->y = (slct->y - 1 >= 0) ? slct->y - 1 : slct->row - 1;
		while (slct->y * slct->col + slct->x >= slct->tot && slct->y > 0)
			(slct->y)--;
	}
	if (c == 66)
	{
		slct->y = (slct->y + 1 < slct->row) ? slct->y + 1 : 0;
		if (slct->y * slct->col + slct->x >= slct->tot)
			slct->y = 0;
	}
	if (c == 68)
	{
		slct->x = (slct->x - 1 >= 0) ? slct->x - 1 : slct->col - 1;
		while (slct->y * slct->col + slct->x >= slct->tot && slct->x > 0)
			(slct->x)--;
	}
	if (c == 67)
	{
		slct->x = (slct->x + 1 < slct->col) ? slct->x + 1 : 0;
		if (slct->y * slct->col + slct->x >= slct->tot)
			slct->x = 0;
	}
}

void	ft_space(t_slct *slct)
{
	if (slct->sel[slct->y * slct->col + slct->x])
		slct->sel[slct->y * slct->col + slct->x] = 0;
	else
		slct->sel[slct->y * slct->col + slct->x] = 1;
	slct->x = (slct->x + 1 < slct->col) ? slct->x + 1 : 0;
	if (slct->x == 0 || slct->y * slct->col + slct->x >= slct->tot)
	{
		slct->x = 0;
		slct->y = (slct->y + 1 < slct->row) ? slct->y + 1 : 0;
		if (slct->y * slct->col + slct->x >= slct->tot)
			slct->y = 0;
	}
}

void	ft_delete(t_slct *slct)
{
	int		i;

	if (slct->av)
	{
		i = slct->y * slct->col + slct->x;
		ft_strdel(slct->av + i);
		while (i + 1 < slct->tot)
		{
			slct->av[i] = slct->av[i + 1];
			slct->len[i] = slct->len[i + 1];
			slct->sel[i] = slct->sel[i + 1];
			i++;
		}
		slct->av[i] = ft_strnew(0);
		slct->len[i] = 0;
		slct->sel[i] = 0;
		slct->tot = slct->tot - 1;
		i = slct->y * slct->col + slct->x;
		if (i == slct->tot)
		{
			slct->x = (i - 1) % slct->col;
			slct->y = (i - 1) / slct->col;
		}
	}
}

int		ft_choice(t_slct *slct)
{
	int		ret;
	char	buf[4] = {0};

	ret = read(0, buf, 3);
	while (ret > 0)
	{
		while (ret < 4)
			buf[ret++] = 0;
		if (buf[0] == 27 && buf[1] == 91 && buf[2] > 64 && buf[2] < 69)
			ft_arrow(buf[2], slct);
		if (buf[0] == 32 && !buf[1])
			ft_space(slct);
		if ((buf[0] == 126 || buf[0] == 127) && !buf[1])
			ft_delete(slct);
		if ((buf[0] == 27 && !buf[1]) || slct->tot == 0)
			return (0);
		ft_clrdsp(slct);
		if (buf[0] == 10 && !buf[1])
			ret = 0;
		else
			ret = read(0, buf, 3);
	}
	return (1);
}

int		ft_select(t_slct *slct)
{
	char	*s[2];
	int		i;

	if (ft_choice(slct) == 0)
		return (0);
	s[0] = NULL;
	s[1] = NULL;
	i = -1;
	while (++i < slct->tot)
	{
		if (slct->sel[i])
		{
			s[0] = (s[1]) ? ft_strjoin(s[1], " ") : NULL;
			ft_strdel(s + 1);
			s[1] = ft_strjoin(s[0], slct->av[i]);
			ft_strdel(s);
		}
	}
	slct->res = s[1];
	return (0);
}
