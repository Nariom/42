/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 09:21:14 by jquilez           #+#    #+#             */
/*   Updated: 2013/12/15 19:07:41 by jquilez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static int			ft_malsplit2(char const *s)
{
	int				i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static int			ft_malsplit(char const *s)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (i != 0 && s[j] == '\n' && s[j] != '\0')
			j++;
		while (s[j] == '\n' && s[j] != '\0')
		{
			j++;
			i++;
		}
		if (s[j] != '\n' && s[j] != '\0')
			i++;
		while (s[j] != '\n' && s[j] != '\0')
			j++;
	}
	return (i);
}

static char			**ft_strsplit_bis(char const *s)
{
	char			**str;
	int				count[2];

	count[0] = 0;
	if (s == NULL)
		return (NULL);
	if ((str = (char **)malloc(sizeof(char *) * ft_malsplit(s) + 1)) == NULL)
		return (NULL);
	while (*s != '\0')
	{
		count[1] = 0;
		while (*s == '\n' && *s++ != '\0')
			str[count[0]++] = ft_strnew(1);
		if (*s != '\n' && *s != '\0')
			str[count[0]] = (char *)malloc(sizeof(char) * ft_malsplit2(s) + 1);
		if (str[count[0]] == NULL)
			return (NULL);
		while (*s != '\n' && *s != '\0')
			str[count[0]][count[1]++] = *(s++);
		str[count[0]++][count[1]] = '\0';
		s++;
	}
	str[count[0]] = NULL;
	return (str);
}

static void			*fill_tab(int const fd, char *tmp, char *buffer)
{
	long			ret;
	char			*tmp2;

	tmp = ft_strnew(1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
		{
			tmp = NULL;
			return (tmp);
		}
		buffer[ret] = '\0';
		tmp2 = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
		tmp = tmp2;
	}
	return (tmp);
}

int					get_next_line(int const fd, char **line)
{
	static char		**tab;
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	static size_t	count;

	tmp = NULL;
	count = (!tab) ? 0 : count + 1;
	if (count != 0)
	{
		*line = tab[count];
		if (!*line)
		{
			hr_clean(tab);
			return (0);
		}
		return (1);
	}
	if ((tmp = fill_tab(fd, tmp, buffer)) == NULL)
		return (-1);
	tab = ft_strsplit_bis(tmp);
	ft_strdel(&tmp);
	*line = tab[count];
	if (!*line)
		return (0);
	return (1);
}
