/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 22:26:32 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/16 17:52:21 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static char	**ft_ls_dir_part(DIR *opnd, struct dirent *rd, int *f)
{
	char	**ret;

	ret = NULL;
	while (rd)
	{
		if (rd->d_name[0] != '.' || f[2] == 1 || (f[1] == 1
				&& rd->d_type == DT_DIR && rd->d_name[1]
				&& rd->d_name[1] != '.'))
		{
			ret = ft_addir(ret, rd->d_name);
			if (!ret)
				return (NULL);
		}
		rd = readdir(opnd);
	}
	return (ret);
}

static char	**ft_list_dir(char *dir, int *f)
{
	DIR				*opnd;
	struct dirent	*rd;
	char			**ret;

	opnd = opendir(dir);
	if (!opnd)
		return (NULL);
	else
	{
		rd = readdir(opnd);
		ret = ft_ls_dir_part(opnd, rd, f);
		if (closedir(opnd) != 0)
			return (NULL);
	}
	return (ret);
}

static int	ft_ls_dd_one(t_ls **pars, t_ls *parsed, t_lslst *dir, int nbp)
{
	int	i;

	*pars = (t_ls *)malloc(sizeof(**pars));
	if (!(*pars))
		return (ft_ls_error(1));
	i = -1;
	while (++i < 6)
		(*pars)->flag[i] = parsed->flag[i];
	(*pars)->path = ft_list_dir(dir->c, parsed->flag);
	if (nbp > 1)
	{
		ft_putchar('\n');
		ft_putstr(dir->c);
		ft_putstr(":\n");
	}
	return (0);
}

int			ft_ls_dd_two(t_ls *pars, t_lslst *dir)
{
	if (pars->path)
	{
		if (ft_ls_ls(pars, dir->c) == -1)
			return (-1);
	}
	else
	{
		if (errno != 0 && errno != ENOENT)
		{
			ft_putstr("ft_ls: ");
			ft_putstr(dir->c);
			ft_putstr(": ");
			perror(NULL);
		}
	}
	return (0);
}

int			ft_ls_dispdir(t_ls *parsed, t_lslst *dir)
{
	char	**tmp;
	t_ls	*pars;
	int		nbp;

	if (parsed->flag[5] == 1)
		return (0);
	if (parsed->flag[5] == 0 && parsed->flag[1] == 0)
		parsed->flag[5] = 1;
	tmp = parsed->path;
	nbp = 0;
	while (*(tmp++))
		nbp++;
	while (dir)
	{
		if (ft_ls_dd_one(&pars, parsed, dir, nbp) == -1)
			return (-1);
		if (ft_ls_dd_two(pars, dir) == -1)
			return (-1);
		dir = dir->next;
	}
	return (0);
}
