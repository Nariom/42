/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 19:05:11 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/07 16:10:50 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define BUF 32
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_lst
{
	char			*name;
	struct s_lst	*link;
	struct s_lst	*next;
}					t_lst;

/*
** LIST_C
*/

t_lst	*ft_new(char *s);
void	ft_add(t_lst **lst, t_lst *new);
void	ft_del(t_lst **lst);
t_lst	*ft_find(t_lst *lst, char *name);
void	ft_print(t_lst *lst);

/*
** ERROR_C
*/

int		interror(const char *str);
void	*voiderror(void);
t_lst	*parse_split_error(char ***p);
int		parse_error(t_lst **lst, char **line, char ***p);

/*
** PARSE_C
*/

int		parse(t_lst **lst, t_lst **start, t_lst **end);

/*
** GET_NEXT_LINE_C
*/

int		get_next_line(int const fd, char **line);

#endif
