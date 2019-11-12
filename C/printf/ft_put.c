/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 12:50:35 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/22 13:50:16 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_iputchar(char c)
{
	return (write(1, &c, 1));
}

int		ft_iputstr(char const *s)
{
	int		i;
	int		ret;

	i = 0;
	if (!s)
		return (ft_iputstr("(null)"));
	while (s && s[i] && i != -1)
	{
		ret = ft_iputchar(s[i]);
		i = (ret != -1) ? i + ret : -1;
	}
	return (i);
}
