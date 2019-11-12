/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:26:25 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/18 18:14:49 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
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
