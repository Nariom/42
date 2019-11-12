/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 02:58:24 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/25 00:02:20 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "libft/libft.h"
# include <stdlib.h>

typedef enum		e_type
{
	END = 0,
	STR = 1,
	LDR = 2,
	RDR = 3,
	PIP = 4,
	SMC = 5,
	TRS = 6,
	WHT = 7,
	QOT = 8,
	DQT = 9,
	BSL = 10,
	STT = 11
}					t_type;

typedef struct		s_token
{
	t_type			type;
	char			*str;
}					t_token;

typedef struct		s_tlst
{
	t_token			token;
	struct s_tlst	*next;
}					t_tlst;

typedef struct		s_stack
{
	t_token			token;
	struct s_stack	*next;
	struct s_stack	*childs;
}					t_stack;

typedef struct		s_env
{
	t_type			cur;
	t_type			prv;
	int				i;
	int				j;
	t_tlst			*l;
}					t_env;

t_tlst				*ft_new(t_type type, char *str);
void				ft_del(t_tlst **lst);
void				ft_print(t_tlst *lst);
int					parser(t_tlst *lst);

#endif
