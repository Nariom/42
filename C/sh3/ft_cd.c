/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 15:39:17 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/04 17:42:13 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

char	*ft_join(char **split)
{
	char	*ret;
	char	*tmp;

	ret = NULL;
	while (*split)
	{
		if (**split)
		{
			tmp = ft_strjoin(ret, "/");
			ft_strdel(&ret);
			ret = tmp;
			tmp = ft_strjoin(ret, *split);
			ft_strdel(&ret);
			ret = tmp;
		}
		split++;
	}
	return (ret);
}

char	*ft_clean(char *path, char **env)
{
	char	**split;
	char	*ret;
	int		i;

	split = ft_strsplit(path, '/');
	i = -1;
	while (split[++i])
	{
		if (ft_strcmp(split[i], "..") == 0 && i != 0)
			ft_memset((void *) split[i - 1], 0, ft_strlen(split[i]));
		if (ft_strcmp(split[i], ".") == 0 || ft_strcmp(split[i], "..") == 0)
			ft_memset((void *) split[i], 0, ft_strlen(split[i]));
		if (ft_strcmp(split[i], "~") == 0 && ft_seekenv(env, "HOME"))
		{
			ft_strdel(split + i);
			split[i] = ft_strdup(*(ft_seekenv(env, "HOME")) + 6);
		}
	}
	ret = ft_join(split);
	ft_ptrstrdel(&split);
	return (ret);
}

char	*ft_path(char **line, char **env)
{
	char	*str[3];

	str[2] = NULL;
	if (ft_seekenv(env, "PWD"))
	{
		str[0] = *(ft_seekenv(env, "PWD")) + 4;
		str[1] = ft_strjoin(str[0], "/");
		str[2] = ft_strjoin(str[1], *line);
		ft_strdel(str + 1);
	}
	if (access(str[2], F_OK) != 0)
	{
		ft_strdel (str + 2);
		str[2] = ft_strdup(*line);
	}
	str[1] = ft_clean(str[2], env);
	ft_strdel(str + 2);
	return (str[1]);
}

void	ft_update(char *path, char **env)
{
	char	**pwd[2];
	char	*tmp;

	pwd[0] = ft_seekenv(env, "PWD");
	pwd[1] = ft_seekenv(env, "OLDPWD");
	if (pwd[0] && pwd[1])
	{
		ft_strdel(pwd[1]);
		tmp = ft_strjoin("OLDPWD=", pwd[0][0] + 4);
		pwd[1][0] = tmp;
	}
	if (pwd[0])
	{
		ft_strdel(pwd[0]);
		tmp = ft_strjoin("PWD=", path);
		pwd[0][0] = tmp;
	}
}

void	ft_cd(char **line, char **env)
{
	char	*tmp[2];

	if (ft_strcmp(line[1], "-") == 0 && ft_seekenv(env, "OLDPWD"))
		tmp[0] = ft_strdup(*(ft_seekenv(env, "OLDPWD")) + 7);
	else
		tmp[0] = ft_path(line + 1, env);
	if (chdir(tmp[0]) != 0)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(line[1]);
	}
	else
		ft_update(tmp[0], env);
	ft_strdel(tmp);
}
