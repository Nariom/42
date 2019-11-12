/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 21:42:19 by rbaudot           #+#    #+#             */
/*   Updated: 2014/04/20 08:19:56 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int	illegal_option(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("\nusage: ./ft_ls [-Ralrt] [file ...]");
	return (-2);
}

static int	parse_option(char *str, t_ls *parsed)
{
	while (*str)
	{
		if (*str == 'l')
			parsed->flag[0] = 1;
		else if (*str == 'R')
			parsed->flag[1] = 1;
		else if (*str == 'a')
			parsed->flag[2] = 1;
		else if (*str == 'r')
			parsed->flag[3] = 1;
		else if (*str == 't')
			parsed->flag[4] = 1;
		else
			return (illegal_option(*str));
		str++;
	}
	return (0);
}

static int	parse_files(int argc, char **argv, t_ls *parsed, int i)
{
	int		j;

	j = i - 1;
	parsed->path = (char **)malloc((argc - j) * sizeof(char *));
	if (!(parsed->path))
		return (-1);
	while (++j < argc)
	{
		parsed->path[j - i] = ft_strdup(argv[j]);
		if (!(parsed->path[j - i]))
			return (-1);
	}
	parsed->path[j - i] = NULL;
	return (0);
}

static int	parse(int argc, char **argv, t_ls *parsed)
{
	int		ddash;
	int		i;

	ddash = 0;
	i = 0;
	while (++i < argc)
	{
		if (!ddash && argv[i][0] == '-' && argv[i][1])
		{
			if (argv[i][1] != '-')
			{
				if (parse_option(argv[i] + 1, parsed) < 0)
					return (-2);
			}
			else if (argv[i][2])
				return (illegal_option('-'));
			else
				ddash = 1;
		}
		else
			return (parse_files(argc, argv, parsed, i));
	}
	return (0);
}

int			alloc_and_parse(int argc, char **argv, t_ls **parsed)
{
	int		i;
	int		ret;

	(*parsed) = (t_ls *)malloc(sizeof(**parsed));
	if (!(*parsed))
		return (-1);
	(*parsed)->path = NULL;
	i = -1;
	while (++i < 6)
		(*parsed)->flag[i] = 0;
	if (argc > 1 && (ret = parse(argc, argv, *parsed)) < 0)
		return (ret);
	if (!((*parsed)->path))
	{
		(*parsed)->path = (char **)malloc(2 * sizeof(char *));
		if (!((*parsed)->path))
			return (-1);
		(*parsed)->path[0] = ft_strdup(".");
		if (!((*parsed)->path[0]))
			return (-1);
		(*parsed)->path[1] = NULL;
	}
	return (0);
}
