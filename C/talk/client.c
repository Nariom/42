/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 19:24:37 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/08 19:54:42 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "talk.h"

int		ft_error(char *err)
{
	ft_putendl(err);
	return (-1);
}

int		ft_send(pid_t pid, size_t len)
{
	int		i;
	int		j;

	i = 0;
	j = (int) (8 * sizeof(size_t));
	while (i < j)
	{
		if (len & (1 << i))
		{
			if (kill(pid, SIGUSR2) == -1)
				return (ft_error("./client: bad pid"));
		}
		else if (kill(pid, SIGUSR1) == -1)
			return (ft_error("./client: bad pid"));
		pause();
		usleep(50);
		i++;
	}
	return (0);
}

void	ft_transmit(pid_t pid, char *msg)
{
	int		i;

	while (*msg)
	{
		i = 0;
		while (i < 8)
		{
			if (*msg & (1 << i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			pause();
			usleep(50);
			i++;
		}
		msg++;
	}
}

void	ft_signal(int signum)
{
	(void) signum;
}

int		main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac != 3)
		return (ft_error("usage: ./client [pid] [msg]"));
	i = 0;
	while (av[1][i])
	{
		if (!ft_isdigit(av[1][i]))
			return (ft_error("./client: pid has non digit char(s)"));
		i++;
	}
	pid = (pid_t) ft_atoi(av[1]);
	if (pid <= 0)
		return (ft_error("./client: bad pid"));
	signal(SIGUSR1, ft_signal);
	if (ft_send(pid, ft_strlen(av[2])) == -1)
		return (-1);
	ft_transmit(pid, av[2]);
	return (0);
}
