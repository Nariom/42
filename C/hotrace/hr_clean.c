/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 18:44:20 by jquilez           #+#    #+#             */
/*   Updated: 2013/12/15 19:10:41 by jquilez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void		hr_clean(char **tab)
{
	int		count;

	count = 0;
	while (tab[count])
	{
		ft_strdel(&(tab[count]));
		count++;
	}
	free(tab);
}
