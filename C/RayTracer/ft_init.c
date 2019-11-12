/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 10:57:29 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/27 11:01:17 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int		ft_key_hook(int key, t_env *env)
{
	if (key == 65307)
		exit (0);
	if (key == 65451)
		env->calc->ambient += 0.1;
	if (key == 65453)
		env->calc->ambient -= 0.1;
	if (key == 119)
		env->cam->origin.z -= 0.1;
	if (key == 115)
		env->cam->origin.z += 0.1;
	if (key == 100)
		env->cam->origin.x += 0.1;
	if (key == 97)
		env->cam->origin.x -= 0.1;
	if (key == 65451 || key == 65453 || key == 119 || key == 97 || key == 100 ||
			key == 115)
	{
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
		env->data = mlx_get_data_addr(env->img, &env->bpp,
										&env->size_line, &env->endian);
		ft_scene(env);
	}
	return (0);
}

static int		ft_expose_hook(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->window, env->img, 0, 0);
	mlx_string_put(env->mlx, env->window, 10, HEIGHT - 10, 0xFFFFFF, INFO);
	return (0);
}

void			ft_init(t_env *env)
{
	ft_calc_cam(env);
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, WIDTH, HEIGHT, TITLE);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->data = mlx_get_data_addr(env->img, &env->bpp,
										&env->size_line, &env->endian);
	env->calc->ambient = (double)AMBIENT;
	ft_scene(env);
	mlx_key_hook(env->window, ft_key_hook, env);
	mlx_expose_hook(env->window, ft_expose_hook, env);
	mlx_loop(env->mlx);
}
