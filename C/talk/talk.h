/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:37:21 by rbaudot           #+#    #+#             */
/*   Updated: 2014/02/08 19:04:23 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_atoi(const char *str);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
int		ft_isdigit(int c);

#endif
