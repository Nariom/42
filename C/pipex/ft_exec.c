/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:19:10 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/31 18:27:55 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_seekenv(char **ptr, char *s)
{
	int		i;

	while (ptr && s && *ptr)
	{
		i = 0;
		while (ptr[0][i] && s[i] && ptr[0][i] == s[i])
			i++;
		if (s[i] == 0 && ptr[0][i] == '=')
			return (ptr);
		ptr++;
	}
	return (NULL);
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
	return (str[2]);
}

int		ft_check(char **line, char **env, char **path)
{
	char		*str;
	struct stat	*buf;
	int			acc;
	int			ret;

	*path = NULL;
	buf = (struct stat *) malloc(sizeof(*buf));
	str = ft_find(line, env);
	ret = stat(str, buf);
	ret = (ret == 0 && (buf->st_mode & S_IXUSR) == 0) ? 1 : 0;
	acc = (access(str, F_OK) != 0) ? 1 : 0;
	if (buf)
		free(buf);
	if (acc || ret)
		ft_strdel(&str);
	if (acc)
		return (ft_error(*line, "Command not found"));
	if (ret)
		return (ft_error(*line, "Permission denied"));
	*path = str;
	return (0);
}
