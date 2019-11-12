/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 13:48:18 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/09 19:01:47 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <curses.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_slct
{
	char			**av;
	char			*res;
	int				*len;
	int				*sel;
	int				tot;
	int				col;
	int				row;
	int				clen;
	int				x;
	int				y;
	int				fd;
	struct termios	*term;
}					t_slct;

/*
** MAIN_C
*/

int		ft_clean(t_slct *slct);
int		ft_clndel(int ret, t_slct *slct);
int		ft_init(struct termios *term, t_slct *slct);
int		ft_clrdsp(t_slct *slct);

/*
** SINGLE_C
*/

t_slct	*ft_get(void);
void	ft_del(void);
void	ft_fill(int ac, char **av, struct termios *term);

/*
** SIGNALS_C
*/

void	ft_sig_cont(int signum);
void	ft_signals(void);

/*
** DISPLAY_C
*/

int		ft_outc(int c);
int		ft_clear(t_slct *slct);
void	ft_display(t_slct *slct);

/*
** SELECT_C
*/

int		ft_select(t_slct *slct);

#endif
