/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 22:26:20 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/16 17:47:54 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ft_ls_scmp(t_lslst *l1, t_lslst *l2, int r)
{
	if (r == 0)
		return (ft_strcmp(l1->p, l2->p));
	else
		return (ft_strcmp(l2->p, l1->p));
}

int		ft_ls_tcmp(t_lslst *l1, t_lslst *l2, int r)
{
	time_t	t1;
	time_t	t2;
	long	n1;
	long	n2;

	t1 = (r == 0) ? l1->s->st_mtimespec.tv_sec : l2->s->st_mtimespec.tv_sec;
	t2 = (r == 0) ? l2->s->st_mtimespec.tv_sec : l1->s->st_mtimespec.tv_sec;
	n1 = (r == 0) ? l1->s->st_mtimespec.tv_nsec : l2->s->st_mtimespec.tv_nsec;
	n2 = (r == 0) ? l2->s->st_mtimespec.tv_nsec : l1->s->st_mtimespec.tv_nsec;
	if (t1 != t2)
		return ((int)(t2 - t1));
	if (t1 == t2 && n1 != n2)
		return ((int)(n2 - n1));
	return (ft_ls_scmp(l1, l2, r));
}
