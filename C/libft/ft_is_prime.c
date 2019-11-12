/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 15:43:22 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 17:16:14 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_prime(int nb)
{
	int	div;
	int	count;

	div = nb;
	count = 0;
	while (div > 0)
	{
		if (nb % div == 0)
			count++;
		div--;
	}
	if (count == 2)
		return (1);
	else
		return (0);
}
