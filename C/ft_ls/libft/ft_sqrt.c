/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 15:49:26 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/01 17:21:21 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		oddnb;
	int		result;

	oddnb = 1;
	result = 0;
	if (nb < 0)
		return (0);
	else
	{
		while (nb > 0)
		{
			nb -= oddnb;
			oddnb += 2;
			result++;
		}
		if (nb == 0)
			return (result);
		else
			return (0);
	}
}
