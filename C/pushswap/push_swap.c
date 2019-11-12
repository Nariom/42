/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 19:34:36 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/29 18:02:35 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(const char *str, int *i, int s)
{
	if (*i != 0)
		write(1, " ", 1);
	write(1, str, s);
	*i = 1;
}

void	ft_lasort(int *i, t_list **la, t_list **lb, t_list **last)
{
	*i = 0;
	*last = ft_last(*la);
	*lb = NULL;
	while (*la && (*la)->next && (!is_sorted(*la) || !is_allmax(*la, *lb)))
	{
		if (is_max(*la, *la))
		{
			ft_print("ra", i, 2);
			ft_lr(la, last);
		}
		else if ((*la)->i > (*la)->next->i)
		{
			ft_print("sa", i, 2);
			ft_swap(la);
		}
		else
		{
			ft_print("pb", i, 2);
			ft_push(lb, ft_pull(la));
		}
	}
	*last = ft_last(*lb);
}

int		main(int ac, char **av)
{
	int		i;
	t_list	*la;
	t_list	*lb;
	t_list	*last;

	i = ac - 1;
	la = NULL;
	while (i > 0)
		ft_push(&la, ft_new(ft_atoi(av[i--])));
	ft_lasort(&i, &la, &lb, &last);
	while (lb)
	{
		while (!is_max(lb, lb))
		{
			ft_print("rrb", &i, 3);
			ft_rr(&lb, &last);
		}
		ft_print("pa", &i, 2);
		ft_push(&la, ft_pull(&lb));
	}
	if (i != 0)
		write(1, "\n", 1);
	ft_del(&la);
	ft_del(&lb);
	return (0);
}
