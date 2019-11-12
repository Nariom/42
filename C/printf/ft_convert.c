/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 16:21:14 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/22 15:00:00 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa(int n)
{
	int		dig;
	int		tmp;
	int		sign;
	char	*res;

	dig = (n < 0) ? 2 : 1;
	tmp = n;
	while (tmp / 10 != 0)
	{
		tmp = tmp / 10;
		dig = dig + 1;
	}
	res = (char *) malloc((dig + 1) * sizeof(*res));
	if (res == NULL)
		return (res);
	res[dig] = '\0';
	sign = (n < 0) ? -1 : 1;
	tmp = n;
	while (--dig > -1)
	{
		res[dig] = (char) ((tmp % 10) * sign + 48);
		tmp = tmp / 10;
	}
	res[0] = (n < 0) ? '-' : res[0];
	return (res);
}

char	*ft_ltoa(long int n)
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
	res = (char *) malloc((dig + 1) * sizeof(*res));
	if (res == NULL)
		return (res);
	res[dig] = '\0';
	sign = (n < 0) ? -1 : 1;
	tmp = n;
	while (--dig > -1)
	{
		res[dig] = (char) ((tmp % 10) * sign + 48);
		tmp = tmp / 10;
	}
	res[0] = (n < 0) ? '-' : res[0];
	return (res);
}

char	*ft_otoa(unsigned int n)
{
	int				dig;
	unsigned int	tmp;
	char			*res;

	dig = 1;
	tmp = n;
	while (tmp / 8 != 0)
	{
		tmp = tmp / 8;
		dig = dig + 1;
	}
	res = (char *) malloc((dig + 1) * sizeof(*res));
	if (res == NULL)
		return (res);
	res[dig] = '\0';
	while (--dig > -1)
	{
		res[dig] = (char) ((n % 8) + 48);
		n = n / 8;
	}
	return (res);
}

char	*ft_utoa(unsigned int n)
{
	int				dig;
	unsigned int	tmp;
	char			*res;

	dig = 1;
	tmp = n;
	while (tmp / 10 != 0)
	{
		tmp = tmp / 10;
		dig = dig + 1;
	}
	res = (char *) malloc((dig + 1) * sizeof(*res));
	if (res == NULL)
		return (res);
	res[dig] = '\0';
	while (--dig > -1)
	{
		res[dig] = (char) ((n % 10) + 48);
		n = n / 10;
	}
	return (res);
}

char	*ft_xtoa(unsigned long int n, char u)
{
	int					dig;
	unsigned long int	tmp;
	char				*res;

	dig = 1;
	tmp = n;
	while (tmp / 16 != 0)
	{
		tmp = tmp / 16;
		dig = dig + 1;
	}
	res = (char *) malloc((dig + 1) * sizeof(*res));
	if (res == NULL)
		return (res);
	res[dig] = '\0';
	while (--dig > -1)
	{
		res[dig] = (char) ((n % 16) + 48);
		res[dig] = (res[dig] > 57) ? res[dig] + 7 + u : res[dig];
		n = n / 16;
	}
	return (res);
}
