/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 19:50:00 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/29 18:02:01 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi(const char *str)
{
	unsigned int	res;
	int				sign;

	if (str)
	{
		sign = 1;
		while (*str && (*str == 32 || (*str > 8 && *str < 14)))
			str++;
		if (*str && (*str == '-' || *str == '+'))
		{
			if (*str == '-')
				sign = -1;
			str++;
		}
		res = 0;
		while (*str && *str >= '0' && *str <= '9')
		{
			res = res * 10 + (unsigned int) (*str - '0');
			str++;
		}
		return ((int) ((unsigned int) sign * res));
	}
	return (0);
}

int		is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->i > lst->next->i)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int		is_max(t_list *lst, t_list *elem)
{
	while (lst)
	{
		if (lst->i > elem->i)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int		is_allmax(t_list *l1, t_list *l2)
{
	while (l1 && l2)
	{
		if (!is_max(l1, l2))
			return (0);
		l1 = l1->next;
	}
	return (1);
}
