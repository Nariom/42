/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 19:45:19 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/09 23:13:14 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_sig_winch(int signum)
{
	(void) signum;
	ft_clrdsp(ft_get());
}

static void	ft_sig_exit(int signum)
{
	ft_clndel(-1, ft_get());
	exit(signum);
}

static void	ft_sig_stop(int signum)
{
	char	cz[2] = {ft_get()->term->c_cc[VSUSP], 0};

	if (isatty(1))
	{
		(void) signum;
		ft_clean(ft_get());
		signal(SIGTSTP, SIG_DFL);
		signal(SIGTTIN, SIG_DFL);
		signal(SIGTTOU, SIG_DFL);
		ioctl(ft_get()->fd, TIOCSTI, cz);
	}
}

void		ft_signals(void)
{
	signal(SIGHUP, ft_sig_exit);
	signal(SIGINT, ft_sig_exit);
	signal(SIGQUIT, ft_sig_exit);
	signal(SIGALRM, ft_sig_exit);
	signal(SIGTERM, ft_sig_exit);
	signal(SIGTSTP, ft_sig_stop);
	signal(SIGTTIN, ft_sig_stop);
	signal(SIGTTOU, ft_sig_stop);
	signal(SIGWINCH, ft_sig_winch);
}

void		ft_sig_cont(int signum)
{
	(void) signum;
	signal(SIGCONT, ft_sig_cont);
	ft_init(ft_get()->term, ft_get());
	ft_signals();
	ft_clrdsp(ft_get());
}
