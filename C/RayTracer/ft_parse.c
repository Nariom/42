/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 10:40:03 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/27 11:06:26 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

char		**ft_parse_error(char **line, char ***tab)
{
	if (line)
		ft_strdel(line);
	if (tab)
		ft_tabdel(*tab);
	return (NULL);
}

char		**ft_parse_tab(int fd, int size, const char *name)
{
	char	*line;
	char	**tab;

	get_next_line(fd, &line);
	if (!line)
		return (NULL);
	if (!(tab = ft_split(line)))
		return (ft_parse_error(&line, NULL));
	if (ft_tablen(tab) != size)
		return (ft_parse_error(&line, &tab));
	if (ft_strcmp(*tab, name) != 0)
		return (ft_parse_error(&line, &tab));
	return (tab);
}

int			ft_parse_cam(t_env **env, int fd)
{
	char	**tab;

	if (!(tab = ft_parse_tab(fd, 4, "origin")))
		return (-1);
	(*env)->cam->origin.x = (double)ft_atoi(tab[1]);
	(*env)->cam->origin.y = (double)ft_atoi(tab[2]);
	(*env)->cam->origin.z = (double)ft_atoi(tab[3]);
	ft_tabdel(tab);
	if (!(tab = ft_parse_tab(fd, 4, "dir")))
		return (-1);
	(*env)->cam->dir.x = (double)ft_atoi(tab[1]);
	(*env)->cam->dir.y = (double)ft_atoi(tab[2]);
	(*env)->cam->dir.z = (double)ft_atoi(tab[3]);
	ft_tabdel(tab);
	if (!(tab = ft_parse_tab(fd, 4, "up")))
		return (-1);
	(*env)->cam->upvec.x = (double)ft_atoi(tab[1]);
	(*env)->cam->upvec.y = (double)ft_atoi(tab[2]);
	(*env)->cam->upvec.z = (double)ft_atoi(tab[3]);
	ft_tabdel(tab);
	return (0);
}

int			ft_parse_light(t_env **env, int fd)
{
	t_llst	*add;
	char	**tab;

	if (!(add = ft_llistnew()))
		return (-1);
	if (!(tab = ft_parse_tab(fd, 4, "origin")))
		return (-1);
	add->light.origin.x = (double)ft_atoi(tab[1]);
	add->light.origin.y = (double)ft_atoi(tab[2]);
	add->light.origin.z = (double)ft_atoi(tab[3]);
	ft_tabdel(tab);
	if (!(tab = ft_parse_tab(fd, 4, "color")))
		return (-1);
	add->light.color.r = (double)ft_atoi(tab[1]);
	add->light.color.g = (double)ft_atoi(tab[2]);
	add->light.color.b = (double)ft_atoi(tab[3]);
	ft_tabdel(tab);
	(*env)->light = ft_llistadd((*env)->light, add);
	return (0);
}
