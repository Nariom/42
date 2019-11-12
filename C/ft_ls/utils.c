/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 22:28:13 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/16 17:51:55 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	**ft_addir(char **tab, char *str)
{
	int		i;
	char	**ret;

	i = 0;
	while (tab && tab[i])
		i++;
	ret = (char **)malloc((i + 2) * sizeof(*ret));
	if (!ret)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		ret[i] = tab[i];
		i++;
	}
	ret[i] = ft_strdup(str);
	if (!ret[i])
		return (NULL);
	ret[i + 1] = NULL;
	if (tab)
		free (tab);
	return (ret);
}

char	*ft_ls_itoa(long int n)
{
	long int	dig;
	long int	tmp;
	long int	sign;
	char		*res;

	dig = (n < 0) ? 2 : 1;
	tmp = n;
	while (tmp / 10 != 0)
	{
		tmp = tmp / 10;
		dig = dig + 1;
	}
	res = (char *)malloc((dig + 1) * sizeof(*res));
	if (res == NULL)
		return (res);
	res[dig] = '\0';
	sign = (n < 0) ? -1 : 1;
	tmp = n;
	while (--dig > -1)
	{
		res[dig] = (char)((tmp % 10) * sign + 48);
		tmp = tmp / 10;
	}
	res[0] = (n < 0) ? '-' : res[0];
	return (res);
}

int		ft_nb_digit(int a)
{
	int	ret;

	ret = 1;
	while (a / 10 != 0)
	{
		a = a / 10;
		ret++;
	}
	return (ret);
}

void	ft_putwht(int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_putchar(' ');
}
