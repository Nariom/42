/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 10:24:48 by jquilez           #+#    #+#             */
/*   Updated: 2013/12/15 19:25:51 by jquilez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char const *s)
{
	while (*s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}

void		ft_putendl(char const *s)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
		ft_putchar('\n');
	}
}
