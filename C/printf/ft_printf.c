/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 14:54:38 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/22 22:25:52 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** flags tab :
** [0] - '#'
** [1] - '0'
** [2] - '-'
** [3] - ' '
** [4] - '+'
** [5] - '''
** [6] - field width (length)
** [7] - '.'
** [8] - '.' (length)
** [9] - 'l'
** [10] - '*'
** [11] - '*' (length)
*/

int		*ft_parse_opt(va_list ap, const char *f, int *i)
{
	int		*tab;
	int		j;

	tab = (int *) malloc(12 * sizeof(*tab));
	j = 0;
	while (tab && j < 12)
		tab[j++] = 0;
	while (tab && f[*i] && (ft_isopt(f[*i]) || ft_isdigit(f[*i])))
	{
		j = *i;
		ft_popt(ap, f, i, tab);
		*i = (j != *i) ? *i : *i + 1;
	}
	return (tab);
}

char	*ft_parse_next(va_list ap, int *tab, char c)
{
	char	*ret;

	ret = NULL;
	if (c == 'd' || c == 'i')
		ret = ft_istr(ap, tab);
	if (c == 'u')
		ret = ft_utoa(va_arg(ap, unsigned int));
	if (c == 'p' || c == 'x' || c == 'X')
		ret = ft_xstr(ap, tab, c);
	if (c == 'o')
		ret = ft_ostr(ap, tab);
	if (c == 'c')
		ret = ft_cstr(ap, tab);
	if (c == 's')
		ret = va_arg(ap, char *);
	return (ret);
}

int		ft_parse(va_list ap, const char *f, int *i)
{
	int		ret;
	int		*tab;
	char	c;
	char	*put;

	ret = 0;
	tab = ft_parse_opt(ap, f, i);
	if (!tab)
		return (-1);
	c = f[*i];
	if (c == '%')
		ret = ft_iputchar('%');
	if (c == '%' || ft_isflag(c))
		(*i)++;
	if (!ft_isflag(c))
		return (ret);
	put = ft_parse_next(ap, tab, c);
	ret = ft_print(tab, c, put);
	if (c != 's')
		ft_strdel(&put);
	free(tab);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	int		i[3];
	va_list	ap;

	i[0] = 0;
	i[1] = 0;
	va_start(ap, format);
	while (format[i[0]] && i[1] != -1)
	{
		while (format[i[0]] && format[i[0]] != '%' && i[2] != -1)
		{
			i[2] = (i[1] != -1) ? ft_iputchar(format[i[0]++]) : -1;
			i[1] = (i[2] != -1) ? i[1] + i[2] : -1;
		}
		if (format[i[0]] && i[1] != -1)
		{
			i[0]++;
			i[2] = (i[1] != -1) ? ft_parse(ap, format, i) : -1;
			i[1] = (i[2] != -1) ? i[1] + i[2] : -1;
		}
	}
	va_end(ap);
	return (i[1]);
}
