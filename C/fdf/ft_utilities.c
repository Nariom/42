/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 17:18:39 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/18 16:49:35 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_ispm(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

char	**ft_strsplit_spc(char *s)
{
	char	**r;
	int		i;
	int		j;
	int		k;

	r = (char **) malloc((ft_strlen(s) / 2 + 2) * sizeof(*r));
	i = 0;
	k = 0;
	while (r && s[i])
	{
		while (s[i] && !ft_isdigit(s[i]) && !ft_ispm(s[i]))
			i++;
		while (s[i] && ft_ispm(s[i]) && s[i + 1] && ft_ispm(s[i + 1]))
			i++;
		j = i;
		while (s[j] && (ft_isdigit(s[j]) || s[j] == '+' || s[j] == '-'))
			j++;
		r[k] = (i != j) ? ft_strsub(s, i, j - i) : NULL;
		k = (i != j) ? k + 1 : k;
		i = j;
	}
	if (r)
		r[k] = NULL;
	return (r);
}

float	ft_abs(float n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	ft_ptrstrdel(char **s)
{
	char	**t;

	if (s)
	{
		t = s;
		while (*t)
		{
			ft_strdel(t);
			t++;
		}
		free(s);
	}
}

int		ft_ptrstrlen(char **s)
{
	int	ret;

	ret = 0;
	while (s && s[ret])
		ret++;
	return (ret);
}
