/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 16:11:44 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/19 10:58:33 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_tlst	*ft_new(t_type type, char *str)
{
	t_tlst	*lst;

	lst = (t_tlst *) malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->token.type = type;
	lst->token.str = str;
	lst->next = NULL;
	return (lst);
}

void	ft_del(t_tlst **lst)
{
	t_tlst	*tmp;

	while (lst && *lst)
	{
		ft_strdel(&(*lst)->token.str);
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	if (lst)
		*lst = NULL;
}

void	ft_print(t_tlst *lst)
{
	t_tlst	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putstr("[ ");
		ft_putnbr(tmp->token.type);
		ft_putstr(" : ");
		ft_putstr(tmp->token.str);
		ft_putstr(" ]");
		if (tmp->next)
			ft_putchar(' ');
		tmp = tmp->next;
	}
	if (lst)
		ft_putchar('\n');
}
