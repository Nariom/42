/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:38:34 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/09 19:52:34 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	res = (char *) malloc((size + 1) * sizeof(*res));
	if (res == NULL)
		return (res);
	i = 0;
	while (i <= size)
		res[i++] = '\0';
	return (res);
}
