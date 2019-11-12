/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 17:27:28 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/31 16:19:05 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void	ft_putstr(const char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putendl(const char *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}

int		ft_error(const char *s1, const char *s2)
{
	ft_putstr(s1);
	if (s1)
		ft_putstr(": ");
	ft_putendl(s2);
	return (-1);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;

	res = NULL;
	if (s1)
	{
		len = ft_strlen(s1);
		res = (char *) malloc((len + 1) * sizeof(*res));
		if (res)
			res = ft_strcpy(res, s1);
	}
	return (res);
}
