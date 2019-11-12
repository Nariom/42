/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 17:24:26 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/19 23:19:29 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_slice(t_color color, int i, int *bnd, t_env e)
{
	int				j;
	unsigned int	c;
	void			*pix;

	j = -1;
	while (++j < HEIGHT)
	{
		pix = (void *) e.img.m + j * e.img.s + i * (e.img.b / 8);
		if (j < bnd[0])
			c = mlx_get_color_value(e.mlx, 16777215);
		else if (j > bnd[1])
			c = mlx_get_color_value(e.mlx, 0);
		else
			c = mlx_get_color_value(e.mlx, color);
		ft_memcpy(pix, (void *) &c, e.img.b / 8);
	}
}

void	ft_draw(t_env e)
{
	t_color	color;
	double	wll;
	int		i[3];
	int		bnd[2];
	int		stp[2];

	i[0] = -1;
	while (++i[0]< WIDTH)
	{
		wll = ft_wall(i[0], e, i + 1, stp);
		i[2] = (int) fabs((double) HEIGHT / wll);
		bnd[0] = (HEIGHT - i[2]) / 2;
		bnd[0] = (bnd[0] < 0) ? 0 : bnd[0];
		bnd[1] = (HEIGHT + i[2]) / 2;
		bnd[1] = (bnd[1] >= HEIGHT) ? HEIGHT - 1 : bnd[1];
		color = YELLOW;
		if (i[1] == 0 && stp[0] == -1)
			color = RED;
		else if (i[1] == 0 && stp[0] == 1)
			color = GREEN;
		else if (i[1] == 1 && stp[1] == -1)
			color = BLUE;
		ft_slice(color, i[0], bnd, e);
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img.i, 0, 0);
}
