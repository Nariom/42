/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 14:51:06 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/26 20:27:12 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms1.h"


void	ft_parse(char **line, char ***env)
{
	if (line && ft_strcmp(*line, "exit") != 0)
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
		else
			ft_exec(line, *env);
	}
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
	char	*str[3];
	char	**ptr[2];

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
		ptr[1] = ft_strsplit(str[1], ' ');
		ft_strdel(str + 1);
		ft_parse(ptr[1], ptr);
	}
	ft_strdel(str);
	ft_ptrstrdel(ptr);
	ft_ptrstrdel(ptr + 1);
	return (0);
}
