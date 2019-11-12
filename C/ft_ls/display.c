/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 22:26:44 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/16 17:49:32 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int	ft_ls_align(t_lslst *tmp, int *tab, long int *tot)
{
	struct passwd	*uid;
	struct group	*gid;

	while (tmp)
	{
		tab[0] = ft_max(tab[0], ft_nb_digit((int)tmp->s->st_nlink));
		uid = getpwuid(tmp->s->st_uid);
		tmp->u = (uid) ? ft_strdup(uid->pw_name) : ft_itoa(tmp->s->st_uid);
		if (!(tmp->u))
			return (ft_ls_error(1));
		tab[1] = ft_max(tab[1], ft_strlen(tmp->u));
		gid = getgrgid(tmp->s->st_gid);
		tmp->g = (gid) ? ft_strdup(gid->gr_name) : ft_itoa(tmp->s->st_gid);
		if (!(tmp->g))
			return (ft_ls_error(1));
		tab[2] = ft_max(tab[2], ft_strlen(tmp->g));
		tab[3] = ft_max(tab[3], ft_nb_digit((int)tmp->s->st_size));
		*tot += tmp->s->st_blocks;
		tmp = tmp->next;
	}
	return (0);
}

static int	ft_ls_write(t_lslst *list, int *tab)
{
	char	*str;

	while (list)
	{
		str = ft_file_mode(list->s->st_mode);
		if (!str)
			return (ft_ls_error(1));
		ft_putstr(str);
		ft_strdel(&str);
		ft_putwht(2 + tab[0] - ft_nb_digit((int)list->s->st_nlink));
		ft_putnbr((int)list->s->st_nlink);
		ft_putwht(1);
		ft_putstr(list->u);
		ft_putwht(2 + tab[1] - ft_strlen(list->u));
		ft_putstr(list->g);
		ft_putwht(2 + tab[2] - ft_strlen(list->g));
		ft_putwht(tab[3] - ft_nb_digit((int)list->s->st_size));
		ft_putnbr((int)list->s->st_size);
		ft_putwht(1);
		ft_putstr(ft_strsub(ctime(&(list->s->st_mtimespec.tv_sec)), 4, 12));
		ft_putwht(1);
		ft_ls_link(list);
		list = list->next;
	}
	return (0);
}

static int	ft_ls_displ(t_lslst *list, int opt)
{
	int			tab[4];
	long int	tot;

	tot = -1;
	while (++tot < 4)
		tab[tot] = 0;
	tot = 0;
	if (ft_ls_align(list, tab, &tot) == -1)
		return (-1);
	if (opt == 1)
	{
		ft_putstr("total ");
		ft_putstr(ft_ls_itoa(tot));
		ft_putchar('\n');
	}
	if (ft_ls_write(list, tab) == -1)
		return (-1);
	return (0);
}

static void	ft_ls_disp(t_lslst *list)
{
	while (list)
	{
		ft_putstr(list->p);
		ft_putchar('\n');
		list = list->next;
	}
}

int			ft_ls_display(t_ls *parsed, t_lslst **sorted, int opt)
{
	t_lslst	*tmp;

	tmp = sorted[1];
	while (tmp)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(tmp->p);
		ft_putstr(": ");
		ft_putstr(tmp->e);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	if (parsed->flag[0] == 0)
		ft_ls_disp(sorted[0]);
	else
	{
		if (ft_ls_displ(sorted[0], opt) == -1)
			return (-1);
	}
	if (ft_ls_dispdir(parsed, sorted[2]) == -1)
		return (-1);
	return (0);
}
