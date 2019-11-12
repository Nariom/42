/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 17:04:33 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/31 18:20:31 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** FT_EXEC_C
*/

int		ft_check(char **line, char **env, char **path);

/*
** FT_STR_C
*/

size_t	ft_strlen(const char *s);
void	ft_putstr(const char *s);
void	ft_putendl(const char *s);
int		ft_error(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);

/*
** FT_STR2_C
*/

void	ft_strdel(char **as);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** FT_STR2_C
*/

char	*ft_strcpy(char *s1, const char *s2);

/*
** FT_PTRSTR_C
*/

char	**ft_ptrstrdup(char **ptr);
void	ft_ptrstrdel(char ***ptr);

#endif
