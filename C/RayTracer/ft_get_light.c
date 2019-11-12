/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 11:26:10 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/27 11:01:01 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		ft_truecolor(t_color *color)
{
	color->r *= 255.0;
	color->g *= 255.0;
	color->b *= 255.0;
	color->r = (color->r > 255.0) ? 255.0 : color->r;
	color->g = (color->g > 255.0) ? 255.0 : color->g;
	color->b = (color->b > 255.0) ? 255.0 : color->b;
	color->r = (color->r < 0.0) ? 0.0 : color->r;
	color->g = (color->g < 0.0) ? 0.0 : color->g;
	color->b = (color->b < 0.0) ? 0.0 : color->b;
}

static t_color	ft_specular(t_env *env, t_light *light, t_point norm,
		t_lst *lst)
{
	t_point		dir;
	t_point		ray;
	t_point		ref;
	t_color		res;
	double		cosf;

	dir = ft_vecmult(env->cam->vecdir, -1.0);
	ray = ft_vecmult(light->vec, -1.0);
	ref.x = 2.0 * ft_dotprod(norm, ray) * norm.x + light->vec.x;
	ref.y = 2.0 * ft_dotprod(norm, ray) * norm.y + light->vec.y;
	ref.z = 2.0 * ft_dotprod(norm, ray) * norm.z + light->vec.z;
	ft_normalize(&ref);
	cosf = ft_dotprod(dir, ref);
	res.r = (cosf > 0.0) ? lst->shine / 10 * light->color.r / 255.0 *
		pow(cosf, 100) : 0.0;
	res.g = (cosf > 0.0) ? lst->shine / 10 * light->color.g / 255.0 *
		pow(cosf, 100) : 0.0;
	res.b = (cosf > 0.0) ? lst->shine / 10 * light->color.b / 255.0 *
		pow(cosf, 100) : 0.0;
	return (res);
}

static t_point	ft_norm(t_env *env, t_lst *lst, t_point inter)
{
	t_point		res;

	if (lst->sphere)
	{
		res.x = lst->sphere->origin.x - inter.x;
		res.y = lst->sphere->origin.y - inter.y;
		res.z = lst->sphere->origin.z - inter.z;
	}
	else if (lst->plane)
		res = lst->plane->equation;
	else if (lst->quad)
	{
		res.x = 2.0 * lst->quad->a * inter.x + lst->quad->d * inter.y;
		res.x += lst->quad->e * inter.z + lst->quad->g;
		res.y = 2.0 * lst->quad->b * inter.y + lst->quad->d * inter.x;
		res.y += lst->quad->f * inter.z + lst->quad->h;
		res.z = 2.0 * lst->quad->c * inter.z + lst->quad->e * inter.x;
		res.z += lst->quad->f * inter.y + lst->quad->i;
	}
	ft_normalize(&res);
	if (lst->quad && ft_dotprod(res, env->cam->vecdir) < 0)
		res = ft_vecmult(res, -1);
	return (res);
}

static t_color	ft_diffspec(t_env *env, t_lst *lst, t_light *l, int shad)
{
	t_color		res;
	t_point		inter;
	t_point		norm;
	double		a;

	inter.x = (env->calc->dist * env->cam->vecdir.x) + env->cam->origin.x;
	inter.y = (env->calc->dist * env->cam->vecdir.y) + env->cam->origin.y;
	inter.z = (env->calc->dist * env->cam->vecdir.z) + env->cam->origin.z;
	l->vec.x = inter.x - l->origin.x;
	l->vec.y = inter.y - l->origin.y;
	l->vec.z = inter.z - l->origin.z;
	ft_normalize(&l->vec);
	if (!shad)
	{
		norm = ft_norm(env, lst, inter);
		a = ft_dotprod(l->vec, norm);
		res = ft_specular(env, l, norm, lst);
		res.r += (a > 0.0) ? lst->ocolor.r / 255.0 * l->color.r / 255.0 * a : 0;
		res.g += (a > 0.0) ? lst->ocolor.g / 255.0 * l->color.g / 255.0 * a : 0;
		res.b += (a > 0.0) ? lst->ocolor.b / 255.0 * l->color.b / 255.0 * a : 0;
	}
	return (res);
}

void			ft_light(t_env *env, t_lst *lst)
{
	t_llst		*light;
	t_color		*color;
	t_color		diffspec;
	int			shad;

	color = env->calc->color;
	color->r = (double)env->calc->ambient * lst->ocolor.r / 255.0;
	color->g = (double)env->calc->ambient * lst->ocolor.g / 255.0;
	color->b = (double)env->calc->ambient * lst->ocolor.b / 255.0;
	light = env->light;
	while (light)
	{
		shad = ft_shadow(env, lst, light->light);
		diffspec = ft_diffspec(env, lst, &light->light, shad);
		if (!shad)
		{
			color->r += diffspec.r;
			color->g += diffspec.g;
			color->b += diffspec.b;
		}
		light = light->next;
	}
	ft_truecolor(color);
}
