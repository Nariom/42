/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 12:30:49 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/14 14:11:25 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return ((int)s1[i] - (int)s2[i]);
}

void		ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		count;
	int		i;
	int		len;
	char	*str;

	count = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char *) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[count++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[count++] = s2[i++];
	}
	str[count] = '\0';
	return (str);
}

size_t		ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char *) * size);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i != size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
