/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:51:06 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/25 21:11:39 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms1.h"

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

void	ft_init(char *av, char **env, char **str, char ***ptr)
{
	(void) av;
	str[0] = ft_strnew(2);
	str[1] = NULL;
	ptr[0] = ft_ptrstrdup(env);
	ptr[1] = NULL;
}

int		main(int ac, char **av, char **env)
{
	int		ret;
	char	*str[3] = {NULL};
	char	**ptr[2] = {NULL};

	ft_init(av[ac - 1], env, str, ptr);
	while (!ptr[1] || ft_strcmp(ptr[1][0], "exit") != 0)
	{
		ft_ptrstrdel(ptr + 1);
		write(0, "$> ", 3);
		ret = read(1, str[0], 1);
		while (ret && **str != '\n')
		{
			str[2] = ft_strjoin(str[1], str[0]);
			ft_strdel(str + 1);
			str[1] = str[2];
			ret = read(1, str[0], 1);
		}
		ft_strdel(str);
		ptr[1] = ft_split(str[1]);
		ft_strdel(str + 1);
		ft_parse(ptr[1], ptr);
		str[0] = ft_strnew(2);
	}
	return (0);
}
