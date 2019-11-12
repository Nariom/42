/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 22:28:06 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/16 17:52:35 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	ft_ls_ins(t_lslst **list, t_lslst *new, t_fcmp f, int r)
{
	t_lslst	*tmp;
	t_lslst	*ptr;

	tmp = *list;
	ptr = NULL;
	while (tmp->next && (*f)(new, tmp, r) > 0)
	{
		ptr = tmp;
		tmp = tmp->next;
	}
	if (tmp == *list && (*f)(new, tmp, r) <= 0)
	{
		ft_lslst_addtop(list, new);
		tmp = NULL;
	}
	if (tmp && ptr && (*f)(new, tmp, r) <= 0)
	{
		ptr->next = new;
		new->next = tmp;
		tmp = NULL;
	}
	if (tmp)
		tmp->next = new;
}

void		ft_ls_sort(t_lslst **list, t_lslst *new, t_ls *parsed)
{
	if (!*list)
		*list = new;
	else
	{
		if (new->s)
		{
			if (parsed->flag[4] == 1)
				ft_ls_ins(list, new, ft_ls_tcmp, parsed->flag[3]);
			else
				ft_ls_ins(list, new, ft_ls_scmp, parsed->flag[3]);
		}
		else
			ft_ls_ins(list, new, ft_ls_scmp, parsed->flag[3]);
	}
}

static void	ft_ls_stat_part(t_ls *parsed, t_lslst **sorted, char *d, t_lslst *l)
{
	t_lslst	**tmp;

	tmp = (l->e) ? sorted + 1 : NULL;
	if (!tmp && S_ISDIR(l->s->st_mode) && ((ft_strcmp(l->p, ".") != 0
				&& ft_strcmp(l->p, "..") != 0) || !d))
		tmp = sorted + 2;
	tmp = (!tmp) ? sorted : tmp;
	ft_ls_sort(tmp, l, parsed);
}

int			ft_ls_stat(t_ls *parsed, t_lslst **sorted, char *d)
{
	struct stat	*buf;
	int			i;
	t_lslst		*new;
	char		*str;

	i = -1;
	while (parsed->path[++i])
	{
		buf = (struct stat *)malloc(sizeof(*buf));
		if (!buf)
			return (ft_ls_error(1));
		str = (d) ? ft_ls_path(d, parsed->path[i]) : ft_strdup(parsed->path[i]);
		if (!str)
			return (ft_ls_error(1));
		if (lstat(str, buf) == 0)
			new = ft_lslst_new(parsed->path[i], buf, NULL, str);
		else
			new = ft_lslst_new(parsed->path[i], NULL, strerror(errno), str);
		if (!new)
			return (ft_ls_error(1));
		ft_ls_stat_part(parsed, sorted, d, new);
	}
	return (0);
}
