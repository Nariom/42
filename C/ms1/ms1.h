/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:50:56 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/26 20:26:58 by rbaudot          ###   ########.fr       */
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

void	ft_exec(char **line, char **env);
void	ft_cd(char **line, char **env);
char	**ft_seekenv(char **ptr, char *s);
void	ft_setenv(char **line, char ***env);
void	ft_unsetenv(char **line, char ***env);

#endif
