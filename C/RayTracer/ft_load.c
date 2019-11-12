/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 10:17:28 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/02 21:22:46 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		ft_bar(t_env *env, int start, int end, int height)
{
	int		i;

	i = start - 6;
	while (++i < end + 5)
		mlx_pixel_put(env->mlx, env->window, i, height - 5, 0x606060);
	i = start - 6;
	while (++i < end + 5)
		mlx_pixel_put(env->mlx, env->window, i, height + 54, 0x606060);
	i = height - 6;
	while (++i < height + 55)
		mlx_pixel_put(env->mlx, env->window, start - 5, i, 0x606060);
	i = height - 6;
	while (++i < height + 55)
		mlx_pixel_put(env->mlx, env->window, end + 5, i, 0x606060);
}

void			ft_load(t_env *env)
{
	static int	start = WIDTH / 5;
	static int	x = WIDTH / 5;
	static int	end = WIDTH - WIDTH / 5;
	static int	height = HEIGHT / 2 - 25;
	int			count;

	if (x <= WIDTH / 5)
		ft_bar(env, start, end, height);
	while (x <= start + (env->o_y / HEIGHT) * (end - start))
	{
		count = height - 1;
		while (++count < height + 50)
			mlx_pixel_put(env->mlx, env->window, x, count, 0x006600);
		x++;
	}
}
