/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:54:20 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/25 00:07:25 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define TOKENS 7
# define STATES 7
# define GAP 8
# include "libft/libft.h"
# include "lexer.h"

typedef enum		e_state
{
	S = 8,
	A = 9,
	B = 10,
	C = 11,
	D = 12,
	E = 13,
	F = 14
}					t_state;

static int		gram[STATES][TOKENS][4] =
{
	{{WHT}, {A, B, WHT}, {A, B, WHT}, {A, B, WHT}, {TRS}, {TRS}},
	{{TRS}, {C, D, WHT}, {E, STR, C, WHT}, {E, STR, C, WHT}, {TRS}, {TRS}},
	{{WHT}, {TRS}, {TRS}, {TRS}, {TRS}, {SMC, S, WHT}},
	{{TRS}, {STR, F, WHT}, {TRS}, {TRS}, {TRS}, {TRS}},
	{{WHT}, {TRS}, {E, STR, C, WHT}, {E, STR, C, WHT}, {PIP, C, WHT}, {WHT}},
	{{TRS}, {TRS}, {LDR, WHT}, {RDR, WHT}, {TRS}, {TRS}},
	{{WHT}, {STR, F, WHT}, {WHT}, {WHT}, {WHT}, {WHT}},
};

t_stack	*new_stk(t_type type, char *str);
void	push(t_stack **stk, t_stack *new);
void	pop(t_stack	**stk);
void	bottom(t_stack **stk, t_stack *new);
void	del(t_stack **stk);

#endif
