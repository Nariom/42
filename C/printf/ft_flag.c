/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 13:40:25 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/22 23:24:16 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_listr(va_list ap, int *tab)
{
	long	l;
	char	*ret;
	char	*tmp;

	ret = NULL;
	l = va_arg(ap, long);
	tmp = ft_ltoa(l);
	if (l >= 0 && tab[4])
		ret = ft_strjoin("+", tmp);
	else if (l >= 0 && tab[3])
		ret = ft_strjoin(" ", tmp);
	if (ret)
		ft_strdel(&tmp);
	else
		ret = tmp;
	return (ret);
}

char	*ft_istr(va_list ap, int *tab)
{
	int		i;
	char	*ret;
	char	*tmp;

	ret = NULL;
	if (tab[8])
		return (ft_listr(ap, tab));
	else
	{
		i = va_arg(ap, int);
		tmp = ft_itoa(i);
		if (i >= 0 && tab[4])
			ret = ft_strjoin("+", tmp);
		else if (i >= 0 && tab[3])
			ret = ft_strjoin(" ", tmp);
	}
	if (ret)
		ft_strdel(&tmp);
	else
		ret = tmp;
	return (ret);
}

char	*ft_xstr(va_list ap, int *tab, char c)
{
	char				*ret;
	char				*ox;
	char				*tmp;

	ox = NULL;
	tmp = NULL;
	if (c == 'p' || (tab[0] && c == 'x'))
		ox = ft_strsub("0x", 0, 2);
	else if (tab[0] && c == 'X')
		ox = ft_strsub("0X", 0, 2);
	if (c == 'x' || c == 'p')
		tmp = ft_xtoa(va_arg(ap, unsigned long int), 32);
	else if (c == 'X')
		tmp = ft_xtoa(va_arg(ap, unsigned long int), 0);
	ret = ft_strjoin(ox, tmp);
	ft_strdel(&ox);
	ft_strdel(&tmp);
	return (ret);
}

char	*ft_ostr(va_list ap, int *tab)
{
	char			*ret;
	char			*o;
	char			*tmp;

	o = NULL;
	if (tab[0])
		o = ft_strsub("0", 0, 1);
	tmp = ft_otoa(va_arg(ap, unsigned int));
	ret = ft_strjoin(o, tmp);
	ft_strdel(&o);
	ft_strdel(&tmp);
	return (ret);
}

char	*ft_cstr(va_list ap, int *tab)
{
	char			*ret;

	(void) tab;
	ret = (char *) malloc(2 * sizeof(*ret));
	if (!ret)
		return (NULL);
	ret[0] = (unsigned char) va_arg(ap, int);
	ret[1] = '\0';
	return (ret);
}
