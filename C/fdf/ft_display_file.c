/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:30:13 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/18 14:15:39 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	(void) e;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		expose_hook(t_env *e)
{
	ft_draw(*e);
	return (0);
}

int		ft_display_file(char **split)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, W, H, "fdf");
	e.s = split;
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
