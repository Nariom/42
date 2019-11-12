/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 10:04:02 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/27 11:08:41 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int		ft_init_base(t_env **env)
{
	(*env) = (t_env *)malloc(sizeof(t_env));
	if (!(*env))
		return (-1);
	(*env)->cam = (t_cam *)malloc(sizeof(t_cam));
	if (!(*env)->cam)
		return (-1);
	(*env)->calc = (t_calc *)malloc(sizeof(t_calc));
	if (!(*env)->calc)
		return (-1);
	(*env)->calc->all_color = (t_color *)malloc(sizeof(t_color));
	if (!(*env)->calc->all_color)
		return (-1);
	(*env)->calc->color = (t_color *)malloc(sizeof(t_color));
	if (!(*env)->calc->color)
		return (-1);
	return (0);
}

static int		ft_act(t_env *env, char **av)
{
	if (ft_init_base(&env) == -1)
	{
		ft_putendl_fd("rt: Malloc error", 2);
		return (-1);
	}
	else if ((open(av[1], O_RDONLY)) == -1)
	{
		ft_error(av[1], 0);
		return (-1);
	}
	else if (ft_parse_map(av[1], &env) == -1)
	{
		ft_putendl_fd("rt: Invalid map", 2);
		return (-1);
	}
	else
		ft_init(env);
	return (0);
}

int				main(int ac, char **av)
{
	t_env		*env;

	env = NULL;
	if (WIDTH >= 320 && HEIGHT >= 240)
	{
		if (ac == 2)
		{
			if ((ft_act(env, av)) == -1)
				return (-1);
		}
		else
		{
			ft_putendl_fd("Usage: ./rt [file]", 2);
			return (-1);
		}
	}
	else
	{
		ft_putendl_fd("Resolution too small", 2);
		return (-1);
	}
	return (0);
}
