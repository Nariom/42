/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 23:25:41 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/25 00:06:04 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "automaton.h"

int		lexres(char *str, t_type type, int i)
{
	if (type == TRS)
	{
		ft_putstr("42sh: syntax error near unexpected token `");
		if (str[i])
			ft_putchar(str[i]);
		else
			ft_putstr("newline");
		ft_putendl("'");
		return (0);
	}
	return (1);
}

int		save(char *str, t_tlst **lst, t_env *e)
{
	t_tlst	*new;

	new = NULL;
	if (fsave[e->prv](str, e, &new) == -1)
		return (-1);
	if (new)
	{
		if (lst && !*lst)
			*lst = new;
		else
			e->l->next = new;
		e->l = new;
	}
	return (0);
}

int		lexer(char *str, t_tlst **lst)
{
	t_env	e;
	
	e.cur = STT;
	e.i = 0;
	e.j = -1;
	e.l = NULL;
	while (e.cur != TRS && e.cur != END)
	{
		e.j++;
		e.prv = e.cur;
		e.cur = (str[e.j] >= 0) ? robot[e.cur][ascii[(int) str[e.j]]] : TRS;
		if (e.prv != e.cur)
		{
			if (robot[e.prv][INPUTS])
				save(str, lst, &e);
			e.i = e.j;
		}
	}
	return (lexres(str, e.cur, e.j));
}

int		main(int ac, char **av)
{
	t_tlst	*lst;
	int		ret;

	lst = NULL;
	if (ac == 2)
	{
		ft_putstr("42sh-1.0$ ");
		ft_putendl(av[1]);
		if (lexer(av[1], &lst))
		{
			ft_print(lst);
			if ((ret = parser(lst)) < 0)
			{
				ft_putstr("ERROR No: ");
				ft_putnbr(ret);
				ft_putendl(" | TOO BAD");
			}
			else
				ft_putendl("GOOD");
		}
	}
	return (0);
}
