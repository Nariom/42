/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 17:22:40 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/07 16:10:23 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		interror(const char *str)
{
	if (str)
		ft_putendl(str);
	else
		perror("lem-in");
	return (-1);
}

void	*voiderror(void)
{
	perror("lem-in");
	return (NULL);
}

t_lst	*parse_split_error(char ***p)
{
	ft_ptrstrdel(p);
	return (NULL);
}

int		parse_error(t_lst **lst, char **line, char ***p)
{
	ft_del(lst);
	ft_strdel(line);
	ft_ptrstrdel(p);
	return (0);
}
