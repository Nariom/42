/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glinford <glinford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 14:28:37 by glinford          #+#    #+#             */
/*   Updated: 2014/03/27 11:08:16 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_lst	*calc_init(t_env *env, t_cam *cam, t_calc *calc)
{
	t_lst		*tmp;
	t_lst		*ret;
	double		val;

	cam->vecdir.x = cam->upleft.x + cam->rightvec.x * cam->indent.x
		* env->x - cam->upvec.x * cam->indent.y * env->y - cam->origin.x;
	cam->vecdir.y = cam->upleft.y + cam->rightvec.y * cam->indent.x
		* env->x - cam->upvec.y * cam->indent.y * env->y - cam->origin.y;
	cam->vecdir.z = cam->upleft.z + cam->rightvec.z * cam->indent.x
		* env->x - cam->upvec.z * cam->indent.y * env->y - cam->origin.z;
	ft_normalize(&cam->vecdir);
	calc->dist = 200000.0;
	ret = NULL;
	tmp = env->list;
	while (tmp)
	{
		val = ft_dist(env, tmp, cam->vecdir, cam->origin);
		ret = (val > 0.0 && val < calc->dist) ? tmp : ret;
		calc->dist = (val > 0.0 && val < calc->dist) ? val : calc->dist;
		tmp = tmp->next;
	}
	calc->t = calc->dist;
	return (ret);
}

static void		calc_color(t_env *env)
{
	env->calc->all_color->r += env->calc->color->r;
	env->calc->all_color->g += env->calc->color->g;
	env->calc->all_color->b += env->calc->color->b;
}

static int		ft_put_color(t_env *env)
{
	env->calc->color->r = (env->calc->all_color->r / (double)RES);
	env->calc->color->g = (env->calc->all_color->g / (double)RES);
	env->calc->color->b = (env->calc->all_color->b / (double)RES);
	ft_pixel_put_img(env, env->calc->color, env->o_x, env->o_y);
	return (0);
}

static void		ft_antialiasing(t_env *env, double delta, double val)
{
	int			count;
	int			i;
	t_lst		*lst;

	count = 0;
	while (count < RES)
	{
		i = 0;
		env->x = env->o_x;
		while (i < val)
		{
			lst = calc_init(env, env->cam, env->calc);
			if (lst)
			{
				env->calc->dist = env->calc->t;
				ft_light(env, lst);
				calc_color(env);
			}
			env->x += delta;
			count++;
			i++;
		}
		env->y += delta;
	}
	ft_put_color(env);
}

void			ft_scene(t_env *env)
{
	double		val;
	double		delta;

	val = sqrt((double)RES);
	delta = 1.0 / val;
	env->o_y = 0.0;
	while (env->o_y < (double)HEIGHT)
	{
		env->o_x = 0.0;
		while (env->o_x < (double)WIDTH)
		{
			env->y = env->o_y;
			env->calc->all_color->r = 0.0;
			env->calc->all_color->g = 0.0;
			env->calc->all_color->b = 0.0;
			ft_antialiasing(env, delta, val);
			env->o_x += 1.0;
		}
		env->o_y += 1.0;
		ft_load(env);
	}
	mlx_put_image_to_window(env->mlx, env->window, env->img, 0, 0);
	mlx_string_put(env->mlx, env->window, 10, HEIGHT - 10, 0xFFFFFF, INFO);
}
