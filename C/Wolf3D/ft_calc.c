/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 22:57:31 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/19 23:16:54 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_flag(t_point dlt, t_point dst, int *map, int *stp)
{
	int		flg;
	int		sid;

	flg = 0;
	while (!flg)
	{
		if (dst.x < dst.y)
		{
			dst.x += dlt.x;
			map[0] += stp[0];
			sid = 0;
		}
		else
		{
			dst.y += dlt.y;
			map[1] += stp[1];
			sid = 1;
		}
		flg = (tab[map[0]][map[1]]);
	}
	return (sid);
}

void	ft_mapstp(int *map, int *stp, t_point dir, t_env e)
{
	map[0] = (int) e.cam.x;
	map[1] = (int) e.cam.y;
	stp[0] = (dir.x < 0) ? -1 : 1;
	stp[1] = (dir.y < 0) ? -1 : 1;
	stp[0] = (dir.x < 0) ? -1 : 1;
	stp[1] = (dir.y < 0) ? -1 : 1;
}

double	ft_wall(int i, t_env e, int *sid, int *stp)
{
	t_point	dir;
	t_point	dlt;
	t_point	dst;
	int		map[2];
	double	wll;

	dir.x = e.eye.x + e.pln.x * (2.0 * (double) i / (double) WIDTH - 1.0);
	dir.y = e.eye.y + e.pln.y * (2.0 * (double) i / (double) WIDTH - 1.0);
	dlt.x = sqrt(1 + (dir.y * dir.y) / (dir.x * dir.x));
	dlt.y = sqrt(1 + (dir.x * dir.x) / (dir.y * dir.y));
	ft_mapstp(map, stp, dir, e);
	if (dir.x < 0)
		dst.x = (e.cam.x - map[0]) * dlt.x;
	else
		dst.x = (map[0] + 1 - e.cam.x) * dlt.x;
	if (dir.y < 0)
		dst.y = (e.cam.y - map[1]) * dlt.y;
	else
		dst.y = (map[1] + 1 - e.cam.y) * dlt.y;
	*sid = ft_flag(dlt, dst, map, stp);
	if (*sid == 0)
		wll = fabs((map[0] - e.cam.x + (1.0 - stp[0]) / 2) / dir.x);
	else
		wll = fabs((map[1] - e.cam.y + (1.0 - stp[1]) / 2) / dir.y);
	return (wll);
}
