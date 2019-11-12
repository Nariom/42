/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 18:22:03 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/07 16:57:58 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		parse(t_lst **lst, t_lst **start, t_lst **end)
{
	t_lst	*t[4];
	char	*line;
	char	**p;
	int		flag[3] = {0};
	int		ant;

	ant = 0;
	while (get_next_line(0, &line))
	{
		if (is_ant(line))
		{
			if (!is_alldigit(line))
				return (parse_error(lst, &line, &p));
			ant = ft_atoi(line);
		}
		else if (is_command(line))
		{
			if (!ant || flag[0] || flag[1])
				return (parse_error(lst, &line, &p));
			flag[0] = (ft_strcmp(line, "start") == 0);
			flag[1] = (ft_strcmp(line, "end") == 0);
			if ((flag[0] && *start) || (flag[1] && *end))
				return (parse_error(lst, &line, &p));
		}
		else if (is_room(line))
		{
			if (!ant || flag[2])
				return (parse_error(lst, &line, &p));
			if (!(p = ft_strsplit(line, ' ')) || !is_name(*p))
				return (parse_error(lst, &line, &p));
			if (ft_find(*lst, *p))
				return (parse_error(lst, &line, &p));
			if (!(t[0] = ft_new(*p)))
				return (parse_error(lst, &line, &p));
			ft_add(lst, t[0]);
			*start = (flag[0]) ? t[0] : *start;
			*end = (flag[1]) ? t[0] : *end;
			flag[0] = 0;
			flag[1] = 0;
			ft_ptrstrdel(&p);
		}
		else if (is_link(line))
		{
			if (!ant || flag[0] || flag[1])
				return (parse_error(lst, &line, &p));
			flag[2] = 1;
			if (!(p = ft_strsplit(line, '-')) || !is_name(*p) || !is_name(p[1]))
				return (parse_error(lst, &line, &p));
			if (!(t[0] = ft_find(*lst, *p)) || !(t[1] = ft_find(*lst, p[1])))
				return (parse_error(lst, &line, &p));
			if (!(t[2] = ft_new(*p)) || !(t[3] = ft_new(p[1])))
			{
				ft_del(t + 2);
				return (parse_error(lst, &line, &p));
			}
			ft_add(&t[0]->link, t[3]);
			ft_add(&t[1]->link, t[2]);
			ft_ptrstrdel(&p);
		}
		else if (!is_comment(line))
			return (parse_error(lst, &line, &p));
		ft_strdel(&line);
	}
	return (ant);
}
