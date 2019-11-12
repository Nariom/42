/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 20:09:00 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/22 20:03:42 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*
** FT_PRINTF
*/

int		ft_printf(const char *format, ...);

/*
** FT_CONVERT
*/

char	*ft_itoa(int n);
char	*ft_ltoa(long int n);
char	*ft_otoa(unsigned int n);
char	*ft_utoa(unsigned int n);
char	*ft_xtoa(unsigned long int n, char u);

/*
** FT_FLAG
*/

char	*ft_istr(va_list ap, int *tab);
char	*ft_xstr(va_list ap, int *tab, char c);
char	*ft_ostr(va_list ap, int *tab);
char	*ft_cstr(va_list ap, int *tab);

/*
** FT_IS
*/

int		ft_isdigit(int c);
int		ft_isopt(int c);
int		ft_isflag(int c);

/*
** FT_PART
*/

void	ft_popt(va_list ap, const char *f, int *i, int *tab);
int		ft_print(int *tab, char c, char *put);

/*
** FT_PUT
*/

int		ft_iputchar(char c);
int		ft_iputstr(char const *s);

/*
** FT_STR
*/

int		ft_strlen(char const *s);
void	ft_strdel(char **as);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);

/*
** FT_UTILITIES
*/

int		ft_atoi(const char *str);
int		ft_nb_digit(int a);
void	ft_padding(int n, char c);

#endif
