/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:31:36 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/14 02:04:25 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	**ft_strsplit_n(char *s)
{
	char	**r;
	int		i[3];

	r = (char **) malloc((ft_strlen(s) + 1) * sizeof(*r));
	i[0] = 0;
	i[1] = 0;
	while (r && s[i[0]])
	{
		if (s[i[0]] == '\n')
		{
			r[i[1]++] = ft_strnew(1);
			i[0]++;
		}
		else
		{
			i[2] = i[0];
			while (s[i[2]] && s[i[2]] != '\n')
				i[2]++;
			r[i[1]++] = ft_strsub(s, i[0], i[2] - i[0]);
			i[0] = (s[i[2]] == '\n') ? i[2] + 1 : i[2];
		}
	}
	if (r)
		r[i[1]] = NULL;
	return (r);
}

int		ft_file_split(int const fd, char ***res)
{
	int		ret;
	char	*buf;
	char	*tmp;
	char	*swp;

	buf = (char *) malloc((BUF + 1) * sizeof(*buf));
	ret = read(fd, buf, BUF);
	while (ret > 0)
	{
		buf[ret] = '\0';
		swp = (tmp) ? ft_strjoin(tmp, buf) : ft_strdup(buf);
		if (!swp)
			return (ft_error("malloc", perror));
		ft_strdel(&tmp);
		tmp = swp;
		ret = read(fd, buf, BUF);
	}
	ft_strdel(&buf);
	if (ret == -1)
		return (ft_error("read", perror));
	*res = ft_strsplit_n(tmp);
	if (!res)
		return (ft_error("malloc", perror));
	ft_strdel(&tmp);
	return (0);
}
