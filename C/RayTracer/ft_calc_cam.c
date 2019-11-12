/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 10:18:09 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/27 11:05:26 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		ft_get_indent(t_env *env)
{
	t_cam	*cam;

	cam = env->cam;
	cam->indent.x = (double)VPW / (double)WIDTH;
	cam->indent.y = (double)VPH / (double)HEIGHT;
}

static void		ft_get_upleft(t_env *env)
{
	t_cam	*cam;

	cam = env->cam;
	cam->upleft.x = cam->origin.x + cam->dir.x * (double)VPD + cam->upvec.x
		* (double)VPH / 2.0 - cam->rightvec.x * (double)VPW / 2.0;
	cam->upleft.y = cam->origin.y + cam->dir.y * (double)VPD + cam->upvec.y
		* (double)VPH / 2.0 - cam->rightvec.y * (double)VPW / 2.0;
	cam->upleft.z = cam->origin.z + cam->dir.z * (double)VPD + cam->upvec.z
		* (double)VPH / 2.0 - cam->rightvec.z * (double)VPW / 2.0;
}

void			ft_calc_cam(t_env *env)
{
	t_cam	*cam;

	cam = env->cam;
	cam->vecdir.x = cam->dir.x - cam->origin.x;
	cam->vecdir.y = cam->dir.y - cam->origin.y;
	cam->vecdir.z = cam->dir.z - cam->origin.z;
	ft_normalize(&cam->vecdir);
	ft_crossprod(cam->upvec, cam->vecdir, &cam->rightvec);
	ft_normalize(&cam->rightvec);
	ft_crossprod(cam->vecdir, cam->rightvec, &cam->upvec);
	ft_normalize(&cam->upvec);
	ft_get_upleft(env);
	ft_get_indent(env);
}
