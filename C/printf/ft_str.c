/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 14:59:45 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/22 14:35:27 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strlen(char const *s)
{
	int		i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	ret = NULL;
	if (s)
	{
		ret = (char *) malloc((len + 1) * sizeof(*ret));
		if (ret)
		{
			ret[len] = '\0';
			while (len > 0)
			{
				ret[len - 1] = s[len + start - 1];
				len--;
			}
		}
	}
	return (ret);
}

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;

	if (s1 && s2)
	{
		if (!*s2)
			return ((char *) s1);
		while (*s1)
		{
			str1 = (char *) s1;
			str2 = (char *) s2;
			while (*str1 == *str2 && *str1 && *str2)
			{
				str1++;
				str2++;
			}
			if (!*str2)
			{
				return ((char *) s1);
			}
			s1++;
		}
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*tmp;
	int		len;

	len = 1;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	ret = (char *) malloc((len) * sizeof(*ret));
	if (ret)
	{
		tmp = ret;
		while (s1 && *s1)
				*tmp++ = *s1++;
		while (s2 && *s2)
				*tmp++ = *s2++;
		*tmp = '\0';
	}
	return (ret);
}
