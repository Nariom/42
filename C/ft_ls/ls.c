/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 21:44:45 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/16 17:50:27 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	t_ls_del(t_ls **parsed)
{
	if (parsed && *parsed)
	{
		if ((*parsed)->path)
			ft_ptrstrdel(&((*parsed)->path));
		free(*parsed);
		*parsed = NULL;
	}
}

char		*ft_ls_path(char *s1, char *s2)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(s1, "/");
	if (!tmp1)
		return (NULL);
	tmp2 = ft_strjoin(tmp1, s2);
	if (!tmp2)
		return (NULL);
	ft_strdel(&tmp1);
	return (tmp2);
}

int			ft_ls_error(int flag)
{
	if (flag)
		perror("ft_ls");
	return (-1);
}

int			ft_ls_ls(t_ls *parsed, char *d)
{
	t_lslst	**sorted;
	int		opt;

	sorted = (t_lslst **)malloc(3 * sizeof(*sorted));
	if (!sorted)
		return (ft_ls_error(1));
	sorted[0] = NULL;
	sorted[1] = NULL;
	sorted[2] = NULL;
	if (ft_ls_stat(parsed, sorted, d) == -1)
		return (-1);
	if (d && sorted[2])
	{
		if (ft_lslst_merge(sorted, sorted[2], parsed) == -1)
			return (-1);
	}
	opt = (d) ? 1 : 0;
	if (ft_ls_display(parsed, sorted, opt) == -1)
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	int		flag;
	int		ret;
	t_ls	*parsed;

	if ((ret = alloc_and_parse(argc, argv, &parsed)) < 0)
	{
		flag = (ret == -1) ? 1 : 0;
		t_ls_del(&parsed);
		return (ft_ls_error(flag));
	}
	if (ft_ls_ls(parsed, NULL) == -1)
		return (-1);
	t_ls_del(&parsed);
	return (0);
}
