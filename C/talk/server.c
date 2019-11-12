/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:57:52 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/08 19:32:07 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "talk.h"

void	ft_strcatch(int signum, int *i, size_t *len, char **s)
{
	(*s)[i[1]] = (signum == SIGUSR2) ? (*s)[i[1]] | 1 << i[0] : (*s)[i[1]];
	i[1] = (i[0] == 7) ? i[1] + 1 : i[1];
	i[0] = (i[0] == 7) ? 0 : i[0] + 1;
	if (i[1] == (int) *len)
	{
		ft_putendl(*s);
		ft_strdel(s);
		i[1] = 0;
		*len = 0;
	}
}

void	ft_receive(int signum)
{
	static int		i[3] = {0, 0, (int) (8 * sizeof(size_t))};
	static size_t	len = 0;
	static char		*str = NULL;

	if (str)
		ft_strcatch(signum, i, &len, &str);
	else
	{
		len = (signum == SIGUSR2) ? len | 1 << i[0] : len;
		if (++i[0] == i[2])
		{
			str = ft_strnew((size_t) len);
			str[len] = 0;
			i[0] = 0;
		}
	}
}

void	ft_signal(int signum, siginfo_t *info, void *data)
{
	(void) data;
	usleep(50);
	ft_receive(signum);
	kill(info->si_pid, SIGUSR1);
}

int		main(void)
{
	pid_t				pid;
	struct sigaction	act;

	pid = getpid();
	ft_putnbr((int) pid);
	ft_putendl("");
	act.sa_handler = NULL;
	act.sa_sigaction = &ft_signal;
	act.sa_mask = 0;
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
