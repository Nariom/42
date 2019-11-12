/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:54:55 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/22 23:19:41 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_int(const char *f, int *i)
{
	int		j;
	char	*str;

	if (f[*i] == '.')
		(*i)++;
	j = *i;
	while (f[j] && ft_isdigit(f[j]))
		j++;
	str = ft_strsub(f, *i, j - *i);
	*i = j;
	if (!str)
		return (0);
	j = ft_atoi(str);
	ft_strdel(&str);
	return (j);
}

void	ft_star(va_list ap, int *tab)
{
	tab[10] = 1;
	tab[11] = va_arg(ap, int);
}

void	ft_popt(va_list ap, const char *f, int *i, int *tab)
{
	if (f[*i] == '#')
		tab[0] = 1;
	else if (f[*i] == '0' && !ft_isdigit(f[*i + 1]))
		tab[1] = 1;
	else if (f[*i] == '-')
		tab[2] = 1;
	else if (f[*i] == ' ')
		tab[3] = 1;
	else if (f[*i] == '+')
		tab[4] = 1;
	else if (f[*i] == 39)
		tab[5] = 1;
	else if (ft_isdigit(f[*i]))
		tab[6] = ft_parse_int(f, i);
	else if (f[*i] == '.')
	{
		tab[7] = 1;
		tab[8] = ft_parse_int(f, i);
	}
	else if (f[*i] == 'l')
		tab[9] = 1;
	else if (f[*i] == '*')
		ft_star(ap, tab);
}

int		ft_print_part(int *tab, char c, char *put)
{
	int		ret;
	int		i;

	if (!tab[7] || (c == 'c' && c == 'p'))
	{
		ret = ft_iputstr(put);
		if (c == 'c' && put[0] == 0)
			ret = ft_iputchar(0);
	}
	else if (c != 's')
	{
		ft_padding(tab[8] - ft_strlen(put), '0');
		ret = ft_iputstr(put);
		ret = (tab[8] > ret) ? tab[8] : ret;
	}
	else
	{
		i = 0;
		ret = 0;
		while (put[i] && i < tab[8])
			ret += ft_iputchar(put[i++]);
	}
	return (ret);
}

int		ft_print(int *tab, char c, char *put)
{
	char	p;
	int		ret;

	if (tab[10])
	{
		tab[6] = (tab[11] > 0) ? tab[11] : -1 * tab[11];
		if (!tab[2] && !tab[7] && tab[11] < 0)
			tab[2] = 1;
		else if (!tab[2] && !tab[3] && !tab[7])
			tab[3] = 1;
	}
	tab[6] = (c == 'c' && put[0] == 0) ? tab[6] - 1 : tab[6];
	p = (tab[1] && tab[6] && !tab[2] && !tab[7]) ? '0' : ' ';
	if ((tab[1] || tab[6]) && !tab[2] && !tab[7])
		ft_padding(tab[6] - ft_strlen(put), p);
	ret = ft_iputstr(put);
	if (c == 'c' && put[0] == 0)
		ret = ft_iputchar(0);
	if (tab[2] && tab[6])
		ft_padding(tab[6] - ft_strlen(put), p);
	tab[6] = (c == 'c' && put[0] == 0) ? tab[6] + 1 : tab[6];
	ret = (tab[6] > ret) ? tab[6] : ret;
	return (ret);
}
