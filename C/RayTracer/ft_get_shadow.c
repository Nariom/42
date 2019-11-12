/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:38:27 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/05 10:11:21 by jquilez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int			ft_shadow(t_env *env, t_lst *lst, t_light light)
{
	t_lst	*tmp;
	double	dist;
	double	val;
	int		flag;

	tmp = env->list;
	dist = ft_dist(env, lst, light.vec, light.origin);
	flag = 0;
	while (tmp && !flag)
	{
		if (tmp != lst)
		{
			val = ft_dist(env, tmp, light.vec, light.origin);
			flag = (val > 0 && val < dist) ? 1 : 0;
		}
		tmp = tmp->next;
	}
	return (flag);
}
