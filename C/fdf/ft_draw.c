/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 17:24:26 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/18 18:44:57 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_one(t_point x1, t_point x2, t_env e)
{
	t_point	d;
	t_point	p;
	int		i;
	float	len;

	if (ft_abs(x2.x - x1.x) >= ft_abs(x2.y - x1.y))
		len = ft_abs(x2.x - x1.x);
	else
		len = ft_abs(x2.y - x1.y);
	d.x = (x2.x - x1.x) / len;
	d.y = (x2.y - x1.y) / len;
	p.x = x1.x + 0.5;
	p.y = x1.y + 0.5;
	i = 0;
	while (i <= len)
	{
		mlx_pixel_put(e.mlx, e.win, p.x, p.y, COL);
		p.x += d.x;
		p.y += d.y;
		i++;
	}
}

void	ft_draw_lines(char **l1, char **l2, int j, t_env e)
{
	int		i;
	t_point	p[2];

	i = 0;
	while (l1[i])
	{
		if (l1[i][0])
		{
			p[0].x = W / DW + (i - j) * X;
			p[0].y = H / DH + (j + i) * Y - ft_atoi(l1[i]) * Z;
			if (l2 && i < ft_ptrstrlen(l2) && l2[i][0])
			{
				p[1].x = W / DW + (i - j - 1) * X;
				p[1].y = H / DH + (j + 1 + i) * Y - ft_atoi(l2[i]) * Z;
				ft_draw_one(p[0], p[1], e);
			}
			if (l1[i + 1])
			{
				p[1].x = W / DW + (i + 1 - j) * X;
				p[1].y = H / DH + (j + i + 1) * Y - ft_atoi(l1[i + 1]) * Z;
				ft_draw_one(p[0], p[1], e);
			}
		}
		i++;
	}
}

void	ft_draw(t_env e)
{
	char	**l1;
	char	**l2;
	int		j;

	l1 = NULL;
	j = 0;
	while (e.s[j])
	{
		l1 = (l1) ? l1 : ft_strsplit_spc(e.s[j]);
		l2 = (e.s[j + 1]) ? ft_strsplit_spc(e.s[j + 1]) : NULL;
		ft_draw_lines(l1, l2, j, e);
		ft_ptrstrdel(l1);
		l1 = l2;
		j++;
	}
	ft_ptrstrdel(l1);
}
