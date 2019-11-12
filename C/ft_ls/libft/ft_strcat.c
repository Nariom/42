/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:23:05 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/15 21:57:49 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	len;

	if (s1 && s2)
	{
		len = (int)ft_strlen(s1);
		ft_strcpy(s1 + len, s2);
	}
	return (s1);
}
