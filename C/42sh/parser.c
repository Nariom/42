/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 19:23:00 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/25 00:04:37 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parser(t_tlst *lst)
{
	t_stack	*stk;
	t_stack	*tmp;
	int		*tab;
	int		i;

	if (!(tmp = new_stk(END, NULL)))
		return (-1);
	push(&stk, tmp);
	if (!(tmp = new_stk((t_type) S, NULL)))
		return (-1);
	push(&stk, tmp);
	while (stk)
	{
		if (stk->token.type > TOKENS)
		{
			tab = gram[stk->token.type - GAP][lst->token.type];
			if (*tab == WHT)
				pop(&stk);
			else if (*tab == TRS)
				return (-1);
			else
			{
				i = 0;
				while (tab[i] != WHT)
					i++;
				while (--i >= 0)
				{
					if (!(tmp = new_stk(tab[i], NULL)))
						return (-1);
					push(&stk, tmp);
				}
			}
		}
		else
		{
			if (stk->token.type == lst->token.type)
			{
				pop(&stk);
				lst = lst->next;
			}
			else
				return (-2);
		}
	}
	return (0);
}
