/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 18:14:11 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/05 16:58:14 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_cleanjoin(char **line, char *str)
{
	char	*join;

	join = ft_strjoin(*line, str);
	if (!join)
		return (-1);
	ft_strdel(line);
	*line = join;
	return (0);
}

static int	ft_sub(char **line, char **buf, int size)
{
	char	*tmp;
	int		len;

	tmp = ft_strsub(*buf, 0, size);
	if (!tmp)
		return (-1);
	if ((ft_cleanjoin(line, tmp)) == -1)
		return (-1);
	ft_strdel(&tmp);
	len = (int) ft_strlen(*buf);
	if (len > size + 1)
	{
		tmp = ft_strsub(*buf, size + 1, len - size - 1);
		if (!tmp)
			return (-1);
		ft_strdel(buf);
		*buf = tmp;
	}
	else
		ft_strdel(buf);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	int			ret;
	static char	*buf = NULL;
	char		*tmp;
	int			size;

	tmp = NULL;
	*line = (buf && !(tmp = ft_strchr(buf, '\n'))) ? buf : NULL;
	buf = (buf && !tmp) ? NULL : buf;
	if (!buf && !(buf = ft_strnew((int) BUF)))
		return (-1);
	while (!tmp && (ret = read(fd, buf, BUF)) && !(tmp = ft_strchr(buf, '\n')))
	{
		if ((ft_cleanjoin(line, buf)) == -1)
			return (-1);
		ft_strclr(buf);
	}
	if (ret == 0 && !*buf)
	{
		ft_strdel(&buf);
		ret = (*line) ? 1 : 0;
		return (ret);
	}
	size = (tmp) ? (int) (tmp - buf) : ret;
	ft_sub(line, &buf, size);
	return (1);
}
