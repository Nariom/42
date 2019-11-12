/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 12:04:13 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/27 11:43:11 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	ft_parse_color(int fd, t_lst *add)
{
	char	**tab;

	if (!(tab = ft_parse_tab(fd, 4, "color")))
		return (-1);
	add->ocolor.r = (double)ft_atoi(tab[1]);
	add->ocolor.g = (double)ft_atoi(tab[2]);
	add->ocolor.b = (double)ft_atoi(tab[3]);
	ft_tabdel(tab);
	return (0);
}

int			ft_parse_sphere(t_env **env, int fd)
{
	t_lst	*add;
	char	**tab;

	if (!(add = ft_listnew(1)))
		return (-1);
	if (!(tab = ft_parse_tab(fd, 4, "origin")))
		return (-1);
	add->sphere->origin.x = (double)ft_atoi(tab[1]);
	add->sphere->origin.y = (double)ft_atoi(tab[2]);
	add->sphere->origin.z = (double)ft_atoi(tab[3]);
	ft_tabdel(tab);
	if (!(tab = ft_parse_tab(fd, 2, "radius")))
		return (-1);
	add->sphere->radius = (double)ft_atoi(tab[1]);
	ft_tabdel(tab);
	if (ft_parse_color(fd, add) == -1)
		return (-1);
	if (!(tab = ft_parse_tab(fd, 2, "shine")))
		return (-1);
	add->shine = (double)ft_atoi(tab[1]);
	ft_tabdel(tab);
	(*env)->list = ft_listadd((*env)->list, add);
	return (0);
}

int			ft_parse_plane(t_env **env, int fd)
{
	t_lst	*add;
	char	**tab;

	add = ft_listnew(2);
	if (!add || !(tab = ft_parse_tab(fd, 4, "origin")))
		return (-1);
	add->plane->origin.x = (double)ft_atoi(tab[1]);
	add->plane->origin.y = (double)ft_atoi(tab[2]);
	add->plane->origin.z = (double)ft_atoi(tab[3]);
	ft_tabdel(tab);
	if (!(tab = ft_parse_tab(fd, 5, "equation")))
		return (-1);
	add->plane->equation.x = (double)ft_atoi(tab[1]);
	add->plane->equation.y = (double)ft_atoi(tab[2]);
	add->plane->equation.z = (double)ft_atoi(tab[3]);
	add->plane->cst = (double)ft_atoi(tab[4]);
	ft_tabdel(tab);
	if (ft_parse_color(fd, add) == -1)
		return (-1);
	if (!(tab = ft_parse_tab(fd, 2, "shine")))
		return (-1);
	add->shine = (double)ft_atoi(tab[1]);
	ft_tabdel(tab);
	(*env)->list = ft_listadd((*env)->list, add);
	return (0);
}

int			ft_parse_quad(t_env **env, int fd)
{
	t_lst	*add;
	char	**tab;

	add = ft_listnew(4);
	if (!add || !(tab = ft_parse_tab(fd, 11, "equation")))
		return (-1);
	add->quad->a = (double)ft_atoi(tab[1]);
	add->quad->b = (double)ft_atoi(tab[2]);
	add->quad->c = (double)ft_atoi(tab[3]);
	add->quad->d = (double)ft_atoi(tab[4]);
	add->quad->e = (double)ft_atoi(tab[5]);
	add->quad->f = (double)ft_atoi(tab[6]);
	add->quad->g = (double)ft_atoi(tab[7]);
	add->quad->h = (double)ft_atoi(tab[8]);
	add->quad->i = (double)ft_atoi(tab[9]);
	add->quad->j = (double)ft_atoi(tab[10]);
	ft_tabdel(tab);
	if (ft_parse_color(fd, add) == -1)
		return (-1);
	if (!(tab = ft_parse_tab(fd, 2, "shine")))
		return (-1);
	add->shine = (double)ft_atoi(tab[1]);
	ft_tabdel(tab);
	(*env)->list = ft_listadd((*env)->list, add);
	return (0);
}
