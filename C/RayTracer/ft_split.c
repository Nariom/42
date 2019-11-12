/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 20:03:53 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/27 11:22:35 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	ft_nbs(char const *s)
{
	int	ret;

	ret = 0;
	while (s && *s)
	{
		while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
			s++;
		ret = (*s) ? ret + 1 : ret;
		while (*s && *s != ' ' && *s != '\t' && *s != '\n')
			s++;
	}
	return (ret);
}

char		**ft_split(char const *s)
{
	char	**ret;
	int		i;
	int		j;
	int		k;

	ret = (s) ? (char **)malloc((ft_nbs(s) + 1) * sizeof(*ret)) : NULL;
	i = 0;
	k = 0;
	while (ret && s[i])
	{
		j = i;
		while (s[j] && s[j] != ' ' && s[j] != '\t' && s[j] != '\n')
			j++;
		ret[k] = (i != j) ? ft_strsub(s, i, j - i) : NULL;
		k = (i != j) ? k + 1 : k;
		i = (i != j) ? j : i + 1;
	}
	if (ret)
		ret[k] = NULL;
	return (ret);
}
