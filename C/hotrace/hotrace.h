/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 12:37:39 by jquilez           #+#    #+#             */
/*   Updated: 2013/12/15 19:30:43 by jquilez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# define BUFF_SIZE 32

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_btree
{
	char			*key;
	char			*val;
	int				hgt;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

/* HR_CLEAN */
void	hr_clean(char **tab);

/* HR_GNL */
int		get_next_line(int const fd, char **line);

/* HR_STR */
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
char	*ft_strjoin(char const *s1, char const *s2);

/* HR_STR2 */
char	*ft_strcpy(char *s1, const char *s2);

/* HR_PUT */
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);

/* HR_BTREE */
void	btree_ins(t_btree **tree, t_btree *parent, char *key, char *val);
char	*btree_search(t_btree *t, char *key);
int		ft_max_hgt(t_btree *left, t_btree *right);

/* HR_ROTATE */
void	btree_rotate(t_btree **tree, t_btree *parent);

#endif
