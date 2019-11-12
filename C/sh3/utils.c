/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 09:08:13 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/07 18:41:58 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_sigint(int sig)
{
	ft_putchar('\n');
	ft_reset();
	exit(sig);
}

int		ft_outc(int c)
{
	return (write(0, &c, 1));
}

int		ft_outstr(char *str)
{
	int		ret[2] = {0};
	int		fd;

	fd = open(ttyname(0), O_WRONLY);
	if (fd == -1)
		return (-1);
	else
	{
		ret[0] = write(fd, str, ft_strlen(str));
		ret[1] = close(fd);
	}
	if (ret[0] == -1 || ret[1] == -1)
		return (-1);
	return (ret[0]);
	return (close(fd));
}

int		ft_error(int reset)
{
	if (reset)
		ft_reset();
	write(1, "error\n", 6);
	return (-1);
}
