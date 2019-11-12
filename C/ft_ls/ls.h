/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 21:45:17 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/16 17:55:07 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <sys/stat.h>
# include <grp.h>
# include <time.h>
# include <unistd.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <stdio.h>
# include "libft/libft.h"

typedef	struct	s_ls
{
	char	**path;
	int		flag[6];
}				t_ls;

typedef struct	s_lslst
{
	char			*p;
	struct stat		*s;
	char			*e;
	char			*u;
	char			*g;
	char			*c;
	struct s_lslst	*next;
}				t_lslst;

typedef int		(*t_fcmp)(t_lslst *, t_lslst *, int);

/*
** CMP
*/

int				ft_ls_scmp(t_lslst *l1, t_lslst *l2, int r);
int				ft_ls_tcmp(t_lslst *l1, t_lslst *l2, int r);

/*
** DIR
*/

int				ft_ls_dispdir(t_ls *parsed, t_lslst *dir);

/*
** DISPLAY
*/

int				ft_ls_display(t_ls *parsed, t_lslst **sorted, int opt);

/*
** FILE
*/

int				ft_ls_link(t_lslst *list);
char			*ft_file_mode(mode_t mode);

/*
** LIST
*/

t_lslst			*ft_lslst_new(char *p, struct stat *s, char *e, char *c);
void			ft_lslst_addtop(t_lslst **list, t_lslst *new);
void			ft_lslst_del(t_lslst **list);
int				ft_lslst_merge(t_lslst **l1, t_lslst *l2, t_ls *parsed);

/*
** LS
*/

char			*ft_ls_path(char *s1, char *s2);
int				ft_ls_error(int flag);
int				ft_ls_ls(t_ls *parsed, char *d);

/*
** PARSE
*/

int				alloc_and_parse(int argc, char **argv, t_ls **parsed);

/*
** SORT
*/

int				ft_ls_stat(t_ls *parsed, t_lslst **sorted, char *d);
void			ft_ls_sort(t_lslst **list, t_lslst *new, t_ls *parsed);

/*
** UTILS
*/

char			**ft_addir(char **tab, char *str);
char			*ft_ls_itoa(long int n);
int				ft_nb_digit(int a);
void			ft_putwht(int n);

#endif
