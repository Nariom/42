/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 20:20:48 by jquilez           #+#    #+#             */
/*   Updated: 2013/12/15 19:20:19 by jquilez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static t_btree	*hr_insert(void)
{
	char		*str1;
	char		*str2;
	int			ret;
	int			flag;
	t_btree		*tree;

	str2 = NULL;
	flag = 0;
	tree = NULL;
	str1 = NULL;
	ret = get_next_line(0, &str1);
	while (ret > 0 && flag == 0)
	{
		flag = (!*str1) ? 1 : flag;
		if (flag == 0)
		{
			if (str2)
				btree_ins(&tree, NULL, str2, str1);
			str2 = (str2) ? NULL : str1;
			ret = get_next_line(0, &str1);
		}
	}
	return (tree);
}

static void		hr_search(t_btree *tree)
{
	char		*str1;
	char		*str2;
	int			ret;

	ret = get_next_line(0, &str1);
	while (ret > 0)
	{
		str2 = btree_search(tree, str1);
		if (str2)
			ft_putendl(str2);
		else
		{
			ft_putstr(str1);
			ft_putendl(": Not found.");
		}
		ret = get_next_line(0, &str1);
	}
}

int				main(void)
{
	t_btree		*tree;

	tree = hr_insert();
	hr_search(tree);
	return (0);
}
