/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:30:13 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/19 20:42:28 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_hook(int keycode, void *e)
{
	t_env	f;
	double	d[3];

	f = *((t_env *) e);
	if (keycode == 65307)
		ft_exit(f, 0);
	d[2] = (keycode == 65361 || keycode == 65362) ? 1 : -1;
	if (keycode == 65362 || keycode == 65364)
		if (tab[(int) (f.cam.x + d[2] * f.eye.x * MSPD)][(int) f.cam.y] == 0)
			f.cam.x = f.cam.x + d[2] * f.eye.x * MSPD;
		if (tab[(int) f.cam.x][(int) (f.cam.y + d[2] * f.eye.y * MSPD)] == 0)
			f.cam.y = f.cam.y + d[2] * f.eye.y * MSPD;
	if (keycode == 65361 || keycode == 65363)
	{
		d[0] = f.eye.x;
		f.eye.x = f.eye.x * cos(d[2] * RSPD) - f.eye.y * sin(d[2] * RSPD);
		f.eye.y = d[0] * sin(d[2] * RSPD) + f.eye.y * cos(d[2] * RSPD);
		d[1] = f.pln.x;
		f.pln.x = f.pln.x * cos(d[2] * RSPD) - f.pln.y * sin(d[2] * RSPD);
		f.pln.y = d[1] * sin(d[2] * RSPD) + f.pln.y * cos(d[2] * RSPD);
	}
	if (keycode > 65360 && keycode < 65365)
		ft_draw(f);
	*((t_env *) e) = f;
	return (0);
}

int		expose_hook(void *e)
{
	ft_draw(*((t_env*) e));
	return (0);
}

int		ft_display_file(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "wolf3d");
	e.img.i = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.img.m = mlx_get_data_addr(e.img.i, &e.img.b, &e.img.s, &e.img.n);
	e.cam.x = (double) CAM_X;
	e.cam.y = (double) CAM_Y;
	e.eye.x = (double) EYE_X;
	e.eye.y = (double) EYE_Y;
	e.pln.x = (double) PLN_X;
	e.pln.y = (double) PLN_Y;
	mlx_expose_hook(e.win, expose_hook, (void *) &e);
	mlx_key_hook(e.win, key_hook, (void *) &e);
	mlx_loop(e.mlx);
	return (0);
}
