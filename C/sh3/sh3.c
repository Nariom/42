/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 08:30:19 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/07 18:52:32 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_keys(int *i, char *buf, char **s, t_lst **l)
{
	if (buf[0] == 12 && !buf[1] && s[1])
		ft_move(i, ft_word(i, s[1], -1) + 3);
	if (buf[0] == 18 && !buf[1] && s[1])
		ft_move(i, ft_word(i, s[1], 1) + 3);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65 && l && *l && i[4] < i[5])
		ft_histup(i, l, s + 1, s);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66 && l && *l && i[4] > 0)
		ft_histdown(i, l, s + 1, s);
	if (buf[0] == 127 && !buf[1] && i[0] > 3)
		ft_delete(i, i + 1, s + 1);
	if ((buf[0] == 7 || buf[0] == 8) && !buf[1] && s[1])
		ft_cut(i, s + 1, s + 2, *buf);
	if ((buf[0] == 2 || buf[0] == 14) && !buf[1] && s[1])
		ft_cutw(i, s + 1, s + 2, *buf);
	if (buf[0] == 11 && !buf[1])
	{
		ft_strdel(s + 2);
		s[2] = ft_strdup(s[1]);
	}
	if (buf[0] == 16 && !buf[1])
		ft_paste(i, s + 1, s[2]);
	if (ft_isprint(buf[0]) && !buf[1])
		ft_put(i, i + 1, buf[0], s + 1);
}

void	ft_loop(char **env)
{
	int		i[6] = {3, 3, 0, 0, 0, 0};
	char	buf[5] = {'\0'};
	char	*s[3] = {NULL};
	t_lst	*l;

	ft_putstr("$> ");
	l = NULL;
	while (!i[2] && (i[3] = read(0, buf, 4)) > 0)
	{
		while (i[3] < 5)
			buf[i[3]++] = 0;
		if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && i[0] < i[1])
			ft_move(i, i[0] + 1);
		if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && i[0] > 3)
			ft_move(i, i[0] - 1);
		if (buf[0] == 27 && buf[1] == 91 && buf[2] == 72 && i[0] > 3)
			ft_move(i, 3);
		if (buf[0] == 27 && buf[1] == 91 && buf[2] == 70 && i[0] < i[1])
			ft_move(i, i[1]);
		ft_keys(i, buf, s, &l);
		if (buf[0] == 10 && !buf[1])
			ft_send(i, &l, s, env);
		if (buf[0] == 4 && !buf[1])
			i[2] = 1;
	}
	ft_putchar('\n');
	ft_del(&l);
}

int		ft_reset(void)
{
	struct termios	term;
	char			*res;

	if (tcgetattr(0, &term) == -1)
		return (ft_error(0));
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	term.c_lflag &= ~(ISIG);
	if (tcsetattr(0, 0, &term) == -1)
		return (ft_error(0));
	if ((res = tgetstr("ei", NULL)) == NULL)
		return (ft_error(0));
	if (tputs(res, 1, ft_outc) == -1)
		return (ft_error(0));
	return (0);
}

int		ft_init(void)
{
	struct termios	term;
	char			*res;

	if ((res = getenv("TERM")) == NULL)
		return (ft_error(0));
	if (tgetent(NULL, res) != 1)
		return (ft_error(0));
	if ((res = tgetstr("im", NULL)) == NULL)
		return (ft_error(1));
	if (tputs(res, 1, ft_outc) == -1)
		return (ft_error(1));
	if (tcgetattr(0, &term) == -1)
		return (ft_error(1));
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_lflag |= ISIG;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (ft_error(1));
	return (0);
}

int		main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	if (ft_init() == -1)
		return (-1);
	signal(SIGINT, ft_sigint);
	ft_loop(env);
	return (ft_reset());
}
