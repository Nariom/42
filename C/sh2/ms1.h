/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:50:56 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/25 19:20:40 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_fd
{
	int			fd[2];
	int			pfd[2];
	char		*prv;
	char		*nxt;
}				t_fd;

char	**ft_split(char const *s);
int		ft_issptb(char c);
int		ft_ispipe(char c);
void	ft_pipe(char **line, char ***env);
void	ft_cmd(char **line, char ***env, t_fd fd);
void	ft_exec(char **line, char **env, t_fd fd);
char	*ft_find(char **line, char **env);
void	ft_cd(char **line, char **env);
char	**ft_seekenv(char **ptr, char *s);
void	ft_setenv(char **line, char ***env);
void	ft_unsetenv(char **line, char ***env);

#endif
