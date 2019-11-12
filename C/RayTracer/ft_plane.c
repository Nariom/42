/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:36:16 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/02 21:11:10 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		ft_plane(t_env *env, t_lst *lst, t_point dir, t_point org)
{
	t_point	a;
	t_point	b;

	a.x = lst->plane->equation.x * (org.x - lst->plane->origin.x);
	a.y = lst->plane->equation.y * (org.y - lst->plane->origin.y);
	a.z = lst->plane->equation.z * (org.z - lst->plane->origin.z);
	b.x = lst->plane->equation.x * dir.x;
	b.y = lst->plane->equation.y * dir.y;
	b.z = lst->plane->equation.z * dir.z;
	env->calc->t = -(a.x + a.y + a.z + lst->plane->cst) / (b.x + b.y + b.z);
	return (env->calc->t);
}
