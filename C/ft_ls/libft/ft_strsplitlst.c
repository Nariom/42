/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:18:35 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/09 19:55:26 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_split_part(char const *s, char c, t_list *ret)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (!s[i])
			return (ret);
		t = ft_strnew((size_t) (j - i + 2));
		t = (t) ? ft_strncpy(t, s + i, (size_t) (j - i + 1)) : NULL;
		if (t)
			t[j - i + 1] = '\0';
		ret->next = (t) ? ft_lstnew((void *)t, (size_t) (j - i + 2)) : NULL;
		if (!(ret->next))
			return (NULL);
		i = j;
		ret = ret->next;
	}
	return (ret);
}

t_list		*ft_strsplitlst(char const *s, char c)
{
	t_list	*ret;
	t_list	*tmp;

	ret = ft_lstnew(NULL, 0);
	if (!ret)
		return (NULL);
	tmp = ft_split_part(s, c, ret);
	if (!tmp)
		return (NULL);
	if (ret != tmp)
	{
		tmp->next = ret;
		ret = ret->next;
		tmp->next->next = NULL;
	}
	return (ret);
}
