/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 18:00:03 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/06 19:13:05 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_slct	*ft_get(void)
{
	static t_slct	*slct = NULL;

	if (!slct)
	{
		slct = (t_slct *) malloc(sizeof(*slct));
		if (slct)
		{
			slct->av = NULL;
			slct->res = NULL;
			slct->len = NULL;
			slct->sel = NULL;
			slct->tot = 0;
			slct->col = 0;
			slct->row = 0;
			slct->x = 0;
			slct->y = 0;
			slct->fd = 0;
		}
	}
	return (slct);
}

void	ft_del(void)
{
	t_slct	*slct;

	slct = ft_get();
	if (slct)
	{
		ft_ptrstrdel(&(slct->av));
		ft_strdel(&(slct->res));
		if (slct->len)
			free(slct->len);
		if (slct->sel)
			free(slct->sel);
		free(slct);
	}
}

void	ft_fill(int ac, char **av, struct termios *term)
{
	int		i;
	char	**ret;
	int		*len;
	int		*sel;

	ret = (char **) malloc(ac * sizeof(*ret));
	len = (int *) malloc((ac - 1) * sizeof(*len));
	sel = (int *) malloc((ac - 1) * sizeof(*sel));
	i = 0;
	while (ret && len && sel && ++i < ac)
	{
		ret[i - 1] = ft_strdup(av[i]);
		len[i - 1] = ft_strlen(av[i]);
		sel[i - 1] = 0;
	}
	if (ret)
		ret[i - 1] = NULL;
	ft_get()->av = ret;
	ft_get()->len = len;
	ft_get()->sel = sel;
	ft_get()->tot = ac - 1;
	ft_get()->fd = open(ttyname(0), O_WRONLY);
	ft_get()->term = term;
}
