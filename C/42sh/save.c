/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 11:49:16 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/19 14:42:40 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		save_err(char **sub)
{
	ft_strdel(sub);
	return (-1);
}

int		save_str(char *str, t_env *e, t_tlst **new)
{
	char	*sub;
	char	*tmp;
	int		k[2];

	k[0] = e->i + (e->prv == BSL || e->prv == QOT || e->prv == DQT);
	k[1] = (e->prv == BSL) ? k[0] + 1 : e->j;
	if (!(sub = ft_strsub(str, k[0], k[1] - k[0])))
		return (-1);
	if (e->l && e->l->token.type == STR)
	{
		if (!(tmp = ft_strjoin(e->l->token.str, sub)))
			return (save_err(&sub));
		ft_strdel(&e->l->token.str);
		ft_strdel(&sub);
		e->l->token.str = tmp;
		return (0);	
	}
	if (!(*new = ft_new(STR, sub)))
		return (save_err(&sub));
	return (0);	
}

int		save_type(char *str, t_env *e, t_tlst **new)
{
	(void) str;
	if (!(*new = ft_new(e->prv, NULL)))
		return (-1);
	return (0);
}
