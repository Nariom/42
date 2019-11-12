/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:36:09 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/04 17:42:56 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

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

void	ft_delvar(char **var, char ***env)
{
	char	**ptr;
	int		i[2];

	i[0] = 0;
	while (env[0][i[0]])
		i[0]++;
	ptr = (char **) malloc(i[0] * sizeof(*ptr));
	i[0] = 0;
	i[1] = 0;
	while (ptr && env[0][i[0]])
	{
		if (var != *env + i[0])
		{
			ptr[i[1]] = ft_strdup(env[0][i[0]]);
			i[1]++;
		}
		i[0]++;
	}
	if (ptr)
	{
		ptr[i[1]] = NULL;
		ft_ptrstrdel(env);
		*env = ptr;
	}
}

void	ft_unsetenv(char **line, char ***env)
{
	char	**ptr;

	if (line[1])
	{
		ptr = ft_seekenv(*env, line[1]);
		if (!ptr)
		{
			ft_putstr("unsetenv: environment variable not found: ");
			ft_putendl(line[1]);
		}
		else
			ft_delvar(ptr, env);
	}
	else
		ft_putendl("unsetenv: usage: unsetenv NAME");
}

void	ft_addvar(char *var, char ***env)
{
	char	**ptr;
	char	**tmp;
	int		i;

	tmp = *env;
	i = 0;
	while (tmp[i])
		i++;
	ptr = (char **) malloc((i + 2) * sizeof(*ptr));
	i = 0;
	while (ptr && tmp[i])
	{
		ptr[i] = ft_strdup(tmp[i]);
		i++;
	}
	if (ptr)
	{
		ptr[i] = var;
		ptr[i + 1] = NULL;
		ft_ptrstrdel(env);
		*env = ptr;
	}
}

void	ft_setenv(char **line, char ***env)
{
	char	**var;
	char	**ptr;
	char	*tmp[2];

	var = ft_strsplit(line[1], '=');
	if (var && *var && *(var + 1))
	{
		ptr = ft_seekenv(*env, *var);
		tmp[0] = ft_strjoin(*var, "=");
		tmp[1] = ft_strjoin(tmp[0], *(var + 1));
		ft_strdel(tmp);
		if (!ptr)
			ft_addvar(tmp[1], env);
		else
		{
			ft_strdel(ptr);
			*ptr = tmp[1];
		}
	}
	else
		ft_putendl("setenv: usage: setenv NAME=VALUE");
	ft_ptrstrdel(&var);
}
