/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 22:14:33 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/04 17:43:10 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int		ft_issptb(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		ft_ispipe(char c)
{
	if (c == '>' || c == '<' || c == '|' || c == ';')
		return (1);
	return (0);
}

int		ft_nbs(char const *s)
{
	int	ret;

	ret = 0;
	while (s && *s)
	{
		while (*s && ft_issptb(*s))
			s++;
		ret = (*s && !ft_ispipe(*s)) ? ret + 1 : ret;
		while (*s && !ft_issptb(*s) && !ft_ispipe(*s))
			s++;
		while (*s && ft_ispipe(*s))
		{
			ret++;
			if ((*s == '<' || *s == '>') && *s == *(s + 1))
				s++;
			s++;
		}
	}
	return (ret);
}

void	ft_split_pipe(int *i, const char *s, char **ret)
{
	while (s[i[1]] && ft_ispipe(s[i[1]]))
	{
		if (s[i[1]] == '|' || s[i[1]] == ';')
			ret[i[2]++] = ft_strsub(s, i[1]++, 1);
		if ((s[i[1]] == '<' || s[i[1]] == '>') && s[i[1] + 1] != s[i[1]])
			ret[i[2]++] = ft_strsub(s, i[1]++, 1);
		if ((s[i[1]] == '<' || s[i[1]] == '>') && s[i[1] + 1] == s[i[1]])
		{
			ret[i[2]++] = ft_strsub(s, i[1], 2);
			i[1] += 2;
		}
	}
}

char	**ft_split(char const *s)
{
	char	**ret;
	int		i[4] = {0};

	i[3] = ft_nbs(s);
	ret = (i[3] > 0) ? (char **) malloc((i[3] + 1) * sizeof(*ret)) : NULL;
	while (ret && s[i[0]])
	{
		while (ft_issptb(s[i[0]]))
			i[0]++;
		i[1] = i[0];
		while (s[i[1]] && !ft_issptb(s[i[1]]) && !ft_ispipe(s[i[1]]))
			i[1]++;
		ret[i[2]] = (i[0] != i[1]) ? ft_strsub(s, i[0], i[1] - i[0]) : NULL;
		i[2] = (i[0] != i[1]) ? i[2] + 1 : i[2];
		ft_split_pipe(i, s, ret);
		if (s[i[0]])
			i[0] = (i[0] != i[1]) ? i[1] : i[0] + 1;
	}
	if (ret)
		ret[i[2]] = NULL;
	return (ret);
}
