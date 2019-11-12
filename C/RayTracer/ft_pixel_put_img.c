/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 11:13:45 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/27 11:26:41 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		ft_pixel_put_img(t_env *env, t_color *color, int x, int y)
{
	int		size;
	int		bpp;
	int		r;
	int		g;
	int		b;

	size = env->size_line;
	bpp = env->bpp;
	r = (int)color->r;
	g = (int)color->g;
	b = (int)color->b;
	env->data[(y * size) + x * (bpp / 8) + 2] = \
		mlx_get_color_value(env->mlx, r);
	env->data[(y * size) + x * (bpp / 8) + 1] = \
		mlx_get_color_value(env->mlx, g);
	env->data[(y * size) + x * (bpp / 8)] = \
		mlx_get_color_value(env->mlx, b);
}
