/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:41:28 by rbaudot           #+#    #+#             */
/*   Updated: 2013/11/27 15:19:41 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	len;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	j = ft_strlen(s) - 1;
	while (j > 0 && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	len = (i >= j) ? 1 : j - i + 2;
	ret = (char *) malloc(len * sizeof(*ret));
	if (!ret)
		return (NULL);
	k = 0;
	while (i <= j)
		ret[k++] = s[i++];
	if (ret)
		ret[k] = '\0';
	return (ret);
}
