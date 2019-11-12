/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 17:56:05 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/30 18:02:20 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
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

int		ft_nbs(char const *s, char c)
{
	int	ret;

	ret = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		ret = (*s) ? ret + 1 : ret;
		while (*s && *s != c)
			s++;
	}
	return (ret);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		k;

	ret = (s) ? (char **) malloc((ft_nbs(s, c) + 1) * sizeof(*ret)) : NULL;
	i = 0;
	k = 0;
	while (ret && s[i])
	{
		j = i;
		while (s[j] && s[j] != c)
			j++;
		ret[k] = (i != j) ? ft_strsub(s, i, j - i) : NULL;
		k = (i != j) ? k + 1 : k;
		i = (i != j) ? j : i + 1;
	}
	if (ret)
		ret[k] = NULL;
	return (ret);
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
