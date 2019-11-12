/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:23:33 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/24 19:21:00 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
