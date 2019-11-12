/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 11:22:23 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/18 18:17:40 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(char *str)
{
	perror(str);
	return (-1);
}

int		main(int argc, char **argv)
{
	int		ret;
	int		fd;
	char	**res;

	if (argc < 2)
	{
		ft_putendl("usage: ./fdf file");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error("open"));
	ret = ft_file_split(fd, &res);
	if (ret == -1)
		return (-1);
	ret = close(fd);
	if (ret == -1)
		return (ft_error("close"));
	if (ft_display_file(res) == -1)
		return (-1);
	return (0);
}
