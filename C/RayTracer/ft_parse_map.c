/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 10:55:38 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/27 11:40:45 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int		ft_sort(char *line, t_env **env, int fd)
{
	int			ret;

	ft_putstr(ft_strtrim(line));
	if (ft_strcmp(ft_strtrim(line), "[cam]") == 0)
		ret = ft_parse_cam(env, fd);
	else if (ft_strcmp(ft_strtrim(line), "[light]") == 0)
		ret = ft_parse_light(env, fd);
	else if (ft_strcmp(ft_strtrim(line), "[sphere]") == 0)
		ret = ft_parse_sphere(env, fd);
	else if (ft_strcmp(ft_strtrim(line), "[plane]") == 0)
		ret = ft_parse_plane(env, fd);
	else if (ft_strcmp(ft_strtrim(line), "[quad]") == 0)
		ret = ft_parse_quad(env, fd);
	else
		return (-1);
	if (ret == -1)
		return (-1);
	ft_putstr_green(" √ \n");
	return (0);
}

int				ft_parse_map(char *map, t_env **env)
{
	int			fd;
	char		*line;

	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "#", 1) != 0 && ft_strlen(line) > 1)
		{
			if ((ft_sort(line, env, fd)) == -1)
			{
				ft_putstr_red(" X\n\n");
				return (-1);
			}
		}
	}
	return (0);
}
