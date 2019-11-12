/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 18:35:24 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/22 19:53:26 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int		ft_isopt(int c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 't' || c == 'z' || c == 'q')
		return (1);
	if (c == '#' || c == '-' || c == '+' || c == 39 || c == '.' || c == ',')
		return (1);
	if (c == ';' || c == ':' || c == '_' || c == ' ' || c == '*')
		return (1);
	return (0);
}

int		ft_isflag(int c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 'o' || c == 'p' || c == 's')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}
