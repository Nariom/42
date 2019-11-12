/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 19:46:34 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/09 20:54:59 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_outc(int c)
{
	return (write(ft_get()->fd, &c, 1));
}

static int	ft_cursor(int col, int row)
{
	char	*res;

	if ((res = tgetstr("cm", NULL)) == NULL)
		return (-1);
	if ((res = tgoto(res, col, row)) == NULL)
		return (-1);
	if (tputs(res, 1, ft_outc) == -1)
		return (-1);
	return (0);
}

static void	ft_update(t_slct *slct, struct winsize *argp)
{
	int		pos;

	pos = slct->y * slct->col + slct->x;
	slct->col = slct->tot / argp->ws_row;
	slct->col = (slct->tot % argp->ws_row > 0) ? slct->col + 1 : slct->col;
	slct->clen = argp->ws_col / slct->col;
	slct->row = argp->ws_row;
	while ((slct->row - 2) * (slct->col - 1) > slct->tot)
			(slct->row)--;
	slct->x = pos % slct->col;
	slct->y = pos / slct->col;
}

int			ft_clear(t_slct *slct)
{
	struct winsize	argp;
	char			*res;
	int				ret;

	ret = 0;
	if ((res = tgetstr("cl", NULL)) == NULL)
		return (-1);
	if (tputs(res, 0, ft_outc) == -1)
		return (-1);
	if (ft_cursor(0, 0) == -1)
		return (-1);
	if (slct)
	{
		ret = ioctl(0, TIOCGWINSZ, &argp);
		if (ret != - 1)
			ft_update(slct, &argp);
		ret = (ret == -1) ? ret : 0;
	}
	return (ret);
}

void		ft_display(t_slct *slct)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = -1;
	while (++i < slct->row && i * slct->col < slct->tot)
	{
		j = -1;
		while (++j < slct->col && (i * slct->col + j) < slct->tot)
		{
			ft_cursor(j * slct->clen, i);
			k = slct->len[i * slct->col + j];
			l = (k > slct->clen - 1) ? slct->clen - 2 : k;
			if (slct->x == j && slct->y == i)
				tputs(tgetstr("us", NULL), 1, ft_outc);
			if (slct->sel[i * slct->col + j])
				tputs(tgetstr("mr", NULL), 1, ft_outc);
			write(slct->fd, slct->av[i * slct->col + j], l);
			if (k > slct->clen - 1)
				write(slct->fd, "~", 1);
			if ((slct->x == j && slct->y == i) || slct->sel[i * slct->col + j])
				tputs(tgetstr("me", NULL), 1, ft_outc);
		}
	}
}
