/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 19:51:20 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/10 00:03:07 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_clean(t_slct *slct)
{
	char	*res;

	ft_clear(NULL);
	slct->term->c_lflag |= ICANON;
	slct->term->c_lflag |= ECHO;
	slct->term->c_lflag &= ~(ISIG);
	if (tcsetattr(0, 0, slct->term) == -1)
		return (-1);
	if ((res = tgetstr("ve", NULL)) == NULL)
		return (-1);
	if (tputs(res, 1, ft_outc) == -1)
		return (-1);
	if ((res = tgetstr("te", NULL)) == NULL)
		return (-1);
	if (tputs(res, 1, ft_outc) == -1)
		return (-1);
	return (0);
}

int			ft_clndel(int ret, t_slct *slct)
{
	if (ft_clean(slct) == -1)
		return (-1);
	close(slct->fd);
	if (slct->res)
		write(1, slct->res, ft_strlen(slct->res));
	ft_del();
	return (ret);
}

int			ft_init(struct termios *term, t_slct *slct)
{
	char			*res;

	if ((res = getenv("TERM")) == NULL)
		return (ft_clndel(-1, slct));
	if (tgetent(NULL, res) != 1)
		return (ft_clndel(-1, slct));
	if ((res = tgetstr("ti", NULL)) == NULL)
		return (ft_clndel(-1, slct));
	if (tputs(res, 1, ft_outc) == -1)
		return (ft_clndel(-1, slct));
	if ((res = tgetstr("vi", NULL)) == NULL)
		return (ft_clndel(-1, slct));
	if (tputs(res, 1, ft_outc) == -1)
		return (ft_clndel(-1, slct));
	if (tcgetattr(0, term) == -1)
		return (ft_clndel(-1, slct));
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_lflag |= ISIG;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (ft_clndel(-1, slct));
	return (0);
}

int			ft_clrdsp(t_slct *slct)
{
	if (ft_clear(slct) == -1)
		return (ft_clndel(-1, slct));
	if (slct->clen < 10)
		write(slct->fd, "Too small", 9);
	else
		ft_display(slct);
	return (0);
}

int			main(int ac, char **av)
{
	struct termios	term;
	t_slct			*slct;

	if (ac == 1)
		return (0);
	if ((slct = ft_get()) == NULL)
		return (-1);
	signal(SIGCONT, ft_sig_cont);
	if (ft_init(&term, slct) == -1)
		return (ft_clndel(-1, slct));
	ft_fill(ac, av, &term);
	ft_signals();
	if (ft_clrdsp(slct) == -1)
		return (ft_clndel(-1, slct));
	ft_select(slct);
	return (ft_clndel(0, slct));
}
