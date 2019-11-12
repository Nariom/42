/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 08:29:07 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/04 17:46:54 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH3_H
# define FT_SH3_H
# include <curses.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_fd
{
	int			fd[2];
	int			pfd[2];
	char		*prv;
	char		*nxt;
}				t_fd;

typedef struct		s_lst
{
	char			*s;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

/*
** SH3.C
*/

int		ft_reset(void);

/*
** UTILITIES_C
*/

void	ft_sigint(int sig);
int		ft_outc(int c);
int		ft_outstr(char *str);
int		ft_error(int reset);

/*
** KEYS_C
*/

int		ft_word(int *i, char *s, int dir);
void	ft_send(int *i, t_lst **l, char **s, char **env);
void	ft_move(int *cur, int pos);
void	ft_delete(int *cur, int *len, char **s);
void	ft_put(int *cur, int *len, char c, char **s);

/*
** STR_C
*/

void	ft_remove(int cur, int len, char **s);
void	ft_save(int cur, int len, char c, char **s);
void	ft_cut(int *i, char **s, char **t, char c);
void	ft_cutw(int *i, char **s, char **t, char c);
void	ft_paste(int *i, char **s, char *t);

/*
** LIST_C
*/

t_lst	*ft_new(char *s);
void	ft_add(t_lst **lst, t_lst *new);
void	ft_del(t_lst **lst);
void	ft_histdown(int *i, t_lst **l, char **s, char **r);
void	ft_histup(int *i, t_lst **l, char **s, char **r);

/*
** SH1-2
*/

char	**ft_split(char const *s);
int		ft_issptb(char c);
int		ft_ispipe(char c);
void	ft_pipe(char **line, char ***env);
void	ft_cmd(char **line, char ***env, t_fd fd);
void	ft_exec(char **line, char **env, t_fd fd);
char	*ft_find(char **line, char **env);
void	ft_cd(char **line, char **env);
char	**ft_seekenv(char **ptr, char *s);
void	ft_setenv(char **line, char ***env);
void	ft_unsetenv(char **line, char ***env);
void	ft_sh(char *s, char **env);

#endif
