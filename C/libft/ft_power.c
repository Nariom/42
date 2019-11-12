/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 15:46:48 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 17:20:56 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	int	res;

	if (power < 0)
		res = 0;
	else
	{
		res = 1;
		while (power > 0)
		{
			res = res * nb;
			power--;
		}
	}
	return (res);
}
