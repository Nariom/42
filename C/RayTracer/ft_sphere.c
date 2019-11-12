/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 09:47:29 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/27 11:23:02 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		ft_calc_sphere(t_env *env, t_lst *lst, t_point dir, t_point org)
{
	t_sphere	*sphere;
	t_calc		*calc;

	sphere = lst->sphere;
	calc = env->calc;
	calc->a = (dir.x * dir.x) + (dir.y * dir.y) + (dir.z * dir.z);
	calc->b = 2.0 * (dir.x * (org.x - sphere->origin.x)
			+ dir.y * (org.y - sphere->origin.y) + dir.z
			* (org.z - sphere->origin.z));
	calc->c = (((org.x - sphere->origin.x) * (org.x -
					sphere->origin.x)) + ((org.y - sphere->origin.y)
				* (org.y - sphere->origin.y))
			+ ((org.z - sphere->origin.z) * (org.z
					- sphere->origin.z)) - (sphere->radius * sphere->radius));
	calc->delta = (calc->b * calc->b) - (4.0 * (calc->a * calc->c));
}

double			ft_sphere(t_env *env, t_lst *lst, t_point dir, t_point org)
{
	t_calc		*calc;

	calc = env->calc;
	ft_calc_sphere(env, lst, dir, org);
	if (calc->delta == 0.0)
		return (-calc->b);
	if (calc->delta > 0.0)
	{
		calc->delta = (double)sqrt(calc->delta);
		calc->t1 = (-calc->b + calc->delta) / (2.0 * calc->a);
		calc->t2 = (-calc->b - calc->delta) / (2.0 * calc->a);
		if (calc->t1 < calc->t2)
			return (calc->t1);
		else
			return (calc->t2);
	}
	return (0);
}
