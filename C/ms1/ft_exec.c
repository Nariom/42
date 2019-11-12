/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:19:10 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/26 20:59:27 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms1.h"

void	ft_fork(char *path, char **line, char **env)
{
	pid_t	pid;
	int		*stat_loc;

	pid = fork();
	if (pid > 0)
		waitpid(pid, stat_loc, 0);
	if (pid == 0)
		execve(path, line, env);
}

void	ft_pwd(char **str, char **line, char **env)
{
	char	**tmp;

	if (access(str[2], F_OK) != 0)
	{
		ft_strdel (str + 2);
		tmp = ft_seekenv(env, "PWD");
		str[2] = NULL;
		if (tmp)
		{
			str[0] = *tmp + 4;
			str[1] = ft_strjoin(str[0], "/");
			str[2] = ft_strjoin(str[1], *line);
			ft_strdel(str + 1);
		}
	}
}

char	*ft_find(char **line, char **env)
{
	char	*str[3];
	char	**ptr[3];

	ptr[2] = ft_seekenv(env, "PATH");
	ptr[0] = (ptr[2]) ? ft_strsplit(ptr[2][0] + 5, ':') : NULL;
	ptr[1] = ptr[0];
	str[2] = NULL;
	while (ptr[1] && access(str[2], F_OK) != 0 && *ptr[1])
	{
		ft_strdel(str + 2);
		str[1] = ft_strjoin(*ptr[1], "/");
		str[2] = ft_strjoin(str[1], *line);
		ft_strdel(str + 1);
		ptr[1]++;
	}
	ft_ptrstrdel(ptr);
	if (access(str[2], F_OK) != 0)
	{
		ft_strdel (str + 2);
		str[2] = ft_strdup(*line);
	}
	ft_pwd(str, line, env);
	return (str[2]);
}

void	ft_exec(char **line, char **env)
{
	char	*str;

	str = ft_find(line, env);
	if (access(str, F_OK) == 0)
		ft_fork(str, line, env);
	else
	{
		ft_putstr("ft_minishell1: command not found: ");
		ft_putendl(*line);
	}
	ft_strdel(&str);
}
