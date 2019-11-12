/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:51:06 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/04 17:51:29 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_exit(char **line, char ***env, t_fd fd)
{
	(void) fd;
	ft_ptrstrdel(env);
	ft_ptrstrdel(&line);
	exit(0);
}

void	ft_cmd(char **line, char ***env, t_fd fd)
{
	if (line)
	{
		if (ft_strcmp(*line, "env") == 0)
			ft_putptrstr(*env);
		else if (ft_strcmp(*line, "cd") == 0)
		{
			if (line[1])
				ft_cd(line, *env);
		}
		else if (ft_strcmp(*line, "setenv") == 0)
		{
			if (line[1])
				ft_setenv(line, env);
		}
		else if (ft_strcmp(*line, "unsetenv") == 0)
			ft_unsetenv(line, env);
		else if (ft_strcmp(*line, "exit") == 0)
			ft_exit(line, env, fd);
		else
			ft_exec(line, *env, fd);
	}
}

int		ft_parse(char **line, char ***env)
{
	int		i;
	int		flag;

	(void) env;
	i = 0;
	flag = 0;
	while (line && line[i] && !flag)
	{
		if (ft_ispipe(*line[i]))
		{
			flag = (i == 0 || ft_ispipe(*line[i - 1])) ? 1 : flag;
			flag = (!line[i + 1] || ft_ispipe(*line[i + 1])) ? 1 : flag;
			if (flag)
			{
				ft_putendl("sh2: parse error");
				return (-1);
			}
		}
		i++;
	}
	ft_pipe(line, env);
	return (0);
}

void	ft_sh(char *s, char **env)
{
	char	**dup;
	char	**line;

	dup = ft_ptrstrdup(env);
	line = ft_split(s);
	ft_parse(line, &env);
	ft_ptrstrdel(&dup);
	ft_ptrstrdel(&line);
}
