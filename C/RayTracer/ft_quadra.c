/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:11:55 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/19 11:18:05 by jquilez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		ft_quad(t_quad q, t_point d, t_point o)
{
	double	calc[6];

	calc[0] = q.a * d.x * d.x + q.b * d.y * d.y + q.c * d.z * d.z;
	calc[0] += q.d * d.x * d.y + q.e * d.x * d.z + q.f * d.y * d.z;
	calc[1] = 2.0 * q.a * o.x * d.x + 2.0 * q.b * o.y * d.y;
	calc[1] += 2.0 * q.c * o.z * d.z + q.d * (o.x * d.y + o.y * d.x);
	calc[1] += q.e * (o.x * d.z + o.z * d.x) + q.f * (o.y * d.z + o.z * d.y);
	calc[1] += q.g * d.x + q.h * d.y + q.i * d.z;
	calc[2] = q.a * o.x * o.x + q.b * o.y * o.y + q.c * o.z * o.z;
	calc[2] += q.d * o.x * o.y + q.e * o.x * o.z + q.f * o.y * o.z + q.g * o.x;
	calc[2] += q.h * o.y + q.i * o.z + q.j;
	if (calc[0] == 0)
		return (1 * (calc[2] / calc[1]));
	else
	{
		calc[3] = calc[1] * calc[1] - 4.0 * calc[0] * calc[2];
		if (calc[3] < 0)
			return (0);
		calc[4] = (-1 * calc[1] - sqrt(calc[3])) / (2.0 * calc[0]);
		calc[5] = (-1 * calc[1] + sqrt(calc[3])) / (2.0 * calc[0]);
		if (calc[4] >= 0 && calc[4] < calc[5])
			return (calc[4]);
		else
			return (calc[5]);
	}
}
