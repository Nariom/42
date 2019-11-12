/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:43:52 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/25 14:16:04 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*tmp;

	tmp = ft_itoa(n);
	if (tmp)
	{
		ft_putstr_fd(tmp, fd);
		ft_strdel(&tmp);
	}
}
