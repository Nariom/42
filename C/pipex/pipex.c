/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 17:20:25 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/31 20:40:39 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_pipe_second(char **line, char *file, char **env, int *fd)
{
	int		i[2];

	i[0] = open(file, O_WRONLY | O_CREAT | O_TRUNC);
	chmod(file, S_IRUSR);
	dup2(fd[0], 0);
	dup2(i[0], 1);
	i[1] = fork();
	if (i[1] < 0)
		return (ft_error("fork", "Fail"));
	if (i[1] == 0)
		execve(*line, line, env);
	else
	{
		wait(NULL);
		close(i[0]);
	}
	return (0);
}

int		ft_pipe_first(char **line, char *file, char **env, int *fd)
{
	int		i[3];

	i[0] = open(file, O_RDONLY);
	dup2(i[0], 0);
	dup2(fd[1], 1);
	i[1] = fork();
	if (i[1] < 0)
		return (ft_error("fork", "Fail"));
	if (i[1] == 0)
	{
		close(fd[0]);
		execve(*line, line, env);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		close(i[0]);
	}
	return (0);
}

int		ft_exec_pipe(char ***line, char **av, char **env)
{
	int		fd[2];
	int		ret;

	if (pipe(fd) < 0)
		return (ft_error("pipe", "Fail"));
	ret = ft_pipe_first(line[0], av[1], env, fd);
	if (ret == -1)
		return (-1);
	ret = ft_pipe_second(line[1], av[4], env, fd);
	return (ret);
}

void	ft_join(char **path, char ***line)
{
	ft_strdel(line[0]);
	line[0][0] = path[0];
	ft_strdel(line[1]);
	line[1][0] = path[1];
}

int		main(int ac, char **av, char **env)
{
	char	*path[2];
	char	**line[2];
	int		ret;

	line[0] = ft_strsplit(av[2], ' ');
	line[1] = ft_strsplit(av[3], ' ');
	ret = 0;
	if (ac != 5)
		ret = ft_error("usage", "./pipex file1 cmd1 cmd2 file2");
	else if (access(av[1], F_OK) != 0)
		ret = ft_error(av[1], "No such file or directory");
	else if (access(av[1], R_OK) != 0)
		ret = ft_error(av[1], "Permission denied");
	else if (ft_check(line[0], env, path) != 0)
		ret = -1;
	else if (ft_check(line[1], env, path + 1) != 0)
		ret = -1;
	else if (access(av[4], F_OK) == 0 && access(av[4], W_OK) != 0)
		ret = ft_error(av[4], "Permission denied");
	ft_join(path, line);
	if (ret == 0)
		ret = ft_exec_pipe(line, av, env);
	ft_ptrstrdel(line);
	ft_ptrstrdel(line + 1);
	return (ret);
}
