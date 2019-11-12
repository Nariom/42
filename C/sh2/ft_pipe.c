/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 00:02:40 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/25 22:23:00 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms1.h"

int		ft_getfd(t_fd *fd)
{
	if (*(fd->nxt) == '|')
	{
		pipe(fd->pfd);
		return (fd->pfd[1]);
	}
	return (1);
}

void	ft_pipexec(char **line, char ***env, int *i, t_fd fd)
{
	int		j;
	char	**l;

	j = *i;
	while (line[j] && !ft_ispipe(*line[j]))
		j++;
	l = ft_ptrstrsub(line, *i, j - *i);
	ft_cmd(l, env, fd);
	ft_ptrstrdel(&l);
	*i = j;
}

void	ft_pipe(char **line, char ***env)
{
	int		i;
	int		j;
	t_fd	fd;

	i = 0;
	while (line && line[i])
	{
		j = i;
		while (line[j] && !ft_ispipe(*line[j]))
			j++;
		fd.prv = (i > 0 && ft_ispipe(*line[i - 1])) ? line[i - 1] : NULL;
		fd.nxt = line[j];
		fd.fd[0] = (fd.prv) ? fd.fd[1] : 0;
		fd.fd[0] = (fd.prv && *line[i - 1] == '|') ? fd.pfd[0] : fd.fd[0];
		fd.fd[1] = (fd.nxt) ? ft_getfd(&fd) : 1;
		if (!ft_ispipe(*line[i]) && (!fd.prv || (*line[i - 1] != '<' && *line[i - 1] != '>')))
			ft_pipexec(line, env, &i, fd);
		if (line[i])
			i++;
	}
}
