/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 10:12:56 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/19 11:27:55 by jquilez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		ft_dist(t_env *env, t_lst *lst, t_point dir, t_point org)
{
	if (lst->sphere)
		return (ft_sphere(env, lst, dir, org));
	else if (lst->plane)
		return (ft_plane(env, lst, dir, org));
	else if (lst->quad)
		return (ft_quad(*(lst->quad), dir, org));
	return (0);
}

t_point		ft_vecmult(t_point p, double d)
{
	t_point	res;

	res.x = p.x * d;
	res.y = p.y * d;
	res.z = p.z * d;
	return (res);
}

double		ft_dotprod(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

void		ft_crossprod(t_point a, t_point b, t_point *res)
{
	res->x = a.y * b.z - b.y * a.z;
	res->y = a.z * b.x - b.z * a.x;
	res->z = a.x * b.y - b.x * a.y;
}

void		ft_normalize(t_point *p)
{
	double	id;

	id = sqrt(((p->x) * (p->x)) + ((p->y) * (p->y)) + ((p->z) * (p->z)));
	(p->x) = (p->x) / id;
	(p->y) = (p->y) / id;
	(p->z) = (p->z) / id;
}
