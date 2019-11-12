/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 17:51:20 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/06 17:00:04 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_lst	*lst;
	t_lst	*start;
	t_lst	*end;
	int		ants;

	lst = NULL;
	start = NULL;
	end = NULL;
	if ((ants = parse(&lst, &start, &end)) == -1)
		return (interror("ERROR"));
	ft_print(start);
	ft_del(&lst);
	return (0);
}
