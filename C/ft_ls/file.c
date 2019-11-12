/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 22:27:07 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/16 17:49:51 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int			ft_ls_link(t_lslst *list)
{
	int		ret;
	char	buf[512];

	ft_putstr(list->p);
	if (S_ISLNK(list->s->st_mode))
	{
		ret = (int)readlink(list->c, buf, sizeof(buf) + 1);
		if (ret != -1)
		{
			buf[ret] = '\0';
			ft_putstr(" -> ");
			ft_putstr(buf);
		}
	}
	ft_putchar('\n');
	return (0);
}

static char	ft_file_type(mode_t mode)
{
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISSOCK(mode))
		return ('s');
	return ('-');
}

char		*ft_file_mode(mode_t mode)
{
	char	*ret;

	ret = (char *)malloc(11 * sizeof(*ret));
	if (!ret)
		return (NULL);
	ret[0] = ft_file_type(mode);
	ret[1] = ((mode & S_IRUSR) != 0) ? 'r' : '-';
	ret[2] = ((mode & S_IWUSR) != 0) ? 'w' : '-';
	ret[3] = ((mode & S_IXUSR) != 0) ? 'x' : '-';
	ret[4] = ((mode & S_IRGRP) != 0) ? 'r' : '-';
	ret[5] = ((mode & S_IWGRP) != 0) ? 'w' : '-';
	ret[6] = ((mode & S_IXGRP) != 0) ? 'x' : '-';
	ret[7] = ((mode & S_IROTH) != 0) ? 'r' : '-';
	ret[8] = ((mode & S_IWOTH) != 0) ? 'w' : '-';
	ret[9] = ((mode & S_IXOTH) != 0) ? 'x' : '-';
	ret[10] = '\0';
	return (ret);
}
