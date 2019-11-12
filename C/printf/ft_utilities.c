/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:55:06 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/22 18:55:08 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_atoi(const char *str)
{
	unsigned int	res;
	int				sign;

	if (str)
	{
		sign = 1;
		while (*str && (*str == 32 || (*str > 8 && *str < 14)))
			str++;
		if (*str && (*str == '-' || *str == '+'))
		{
			if (*str == '-')
				sign = -1;
			str++;
		}
		res = 0;
		while (*str && *str >= '0' && *str <= '9')
		{
			res = res * 10 + (unsigned int) (*str - '0');
			str++;
		}
		return ((int) ((unsigned int) sign * res));
	}
	return (0);
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

void	ft_padding(int n, char c)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_iputchar(c);
}
