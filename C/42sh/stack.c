/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 19:37:32 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/25 00:02:00 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_stack	*new_stk(t_type type, char *str)
{
	t_stack	*stk;

	stk = (t_stack *) malloc(sizeof(*stk));
	if (!stk)
		return (NULL);
	stk->token.type = type;
	if (str)
		stk->token.str = ft_strdup(str);
	else
		stk->token.str = NULL;
	stk->next = NULL;
	stk->childs = NULL;
	return (stk);
}

void	push(t_stack **stk, t_stack *new)
{
	if (stk && *stk && new)
		new->next = *stk;
	if (stk && new)
		*stk = new;
}

void	pop(t_stack	**stk)
{
	t_stack	*tmp;

	if (stk)
	{
		tmp = *stk;
		*stk = (*stk)->next;
		ft_strdel(&tmp->token.str);
		free(tmp);
	}
}

void	bottom(t_stack **stk, t_stack *new)
{
	t_stack	*tmp;

	if (stk && new)
	{
		if (*stk)
		{
			tmp = *stk;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			*stk = new;
	}
}

void	del(t_stack **stk)
{
	if (stk && *stk)
	{
		del(&(*stk)->next);
		del(&(*stk)->childs);
		ft_strdel(&(*stk)->token.str);
		free(*stk);
		*stk = NULL;
	}
}
