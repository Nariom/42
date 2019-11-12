/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 06:20:11 by rbaudot           #+#    #+#             */
/*   Updated: 2014/03/24 18:06:14 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATON_H
# define AUTOMATON_H
# define INPUTS 11
# define STATES 12
# define NOO 0
# define YES 1

/*
** INPUT	type	name			corresponding ascii char(s)
** 0		END		nul				\0
** 1		STR		chars			!#$%&()*+,-./:=?@[]^_`{}~ [0-9] [A-Z] [a-z]
** 2		WHT		whitespaces		' ' \t \r \n \v \f
** 3		QOT		single quote	'
** 4		DQT		double quote	"
** 5		BSL		backslash		\
** 6		LRD		left redir		<
** 7		RDR		right redir		>
** 8		PIP		pipe			|
** 9		SMC		semicolon		;
** 10		TRS		trash			[-128,-1] [1,8] [14,31]
**
** STATE	type	name			accepting	token
** 0		END		end				yes			no
** 1		STR		string			yes			yes
** 2		WHT		whitespace		yes			no
** 3		QOT		single quote	no			yes
** 4		DQT		double quote	no			yes
** 5		BSL		back slash		no			yes
** 6		LRD		left redir		no			yes
** 7		RDR		right redir		no			yes
** 8		PIP		pipe			no			yes
** 9		SMC		semicolon		yes			yes
** 10		TRS		trash			no			no
** 11		STT		start			yes			no
** (accepting states go through END)
*/ 

static t_type		ascii[128] = 
{
	END, TRS, TRS, TRS, TRS, TRS, TRS, TRS,
	TRS, WHT, WHT, WHT, WHT, WHT, TRS, TRS,
	TRS, TRS, TRS, TRS, TRS, TRS, TRS, TRS,
	TRS, TRS, TRS, TRS, TRS, TRS, TRS, TRS,
	WHT, STR, DQT, STR, STR, STR, STR, QOT,
	STR, STR, STR, STR, STR, STR, STR, STR,
	STR, STR, STR, STR, STR, STR, STR, STR,
	STR, STR, STR, SMC, LDR, STR, RDR, STR,
	STR, STR, STR, STR, STR, STR, STR, STR,
	STR, STR, STR, STR, STR, STR, STR, STR,
	STR, STR, STR, STR, STR, STR, STR, STR,
	STR, STR, STR, STR, BSL, STR, STR, STR,
	STR, STR, STR, STR, STR, STR, STR, STR,
	STR, STR, STR, STR, STR, STR, STR, STR,
	STR, STR, STR, STR, STR, STR, STR, STR,
	STR, STR, STR, STR, PIP, STR, STR, TRS
};

static t_type		robot[STATES][INPUTS + 1] =
{
	{TRS, TRS, TRS, TRS, TRS, TRS, TRS, TRS, TRS, TRS, TRS, NOO},
	{END, STR, LDR, RDR, PIP, SMC, TRS, WHT, QOT, DQT, BSL, YES},
	{TRS, STR, TRS, TRS, TRS, TRS, TRS, LDR, QOT, DQT, BSL, YES},
	{TRS, STR, TRS, TRS, TRS, TRS, TRS, RDR, QOT, DQT, BSL, YES},
	{TRS, STR, TRS, TRS, TRS, TRS, TRS, PIP, QOT, DQT, BSL, YES},
	{END, STR, LDR, RDR, TRS, TRS, TRS, STT, QOT, DQT, BSL, YES},
	{TRS, TRS, TRS, TRS, TRS, TRS, TRS, TRS, TRS, TRS, TRS, NOO},
	{END, STR, LDR, RDR, PIP, SMC, TRS, WHT, QOT, DQT, BSL, NOO},
	{TRS, QOT, QOT, QOT, QOT, QOT, TRS, QOT, WHT, QOT, QOT, YES},
	{TRS, DQT, DQT, DQT, DQT, DQT, TRS, DQT, DQT, WHT, DQT, YES},
	{TRS, WHT, WHT, WHT, WHT, WHT, TRS, WHT, WHT, WHT, WHT, YES},
	{END, STR, LDR, RDR, TRS, TRS, TRS, STT, QOT, DQT, BSL, NOO}
};

int		save_err(char **sub);
int		save_str(char *str, t_env *e, t_tlst **new);
int		save_type(char *str, t_env *e, t_tlst **new);

static int	(*fsave[INPUTS])(char *str, t_env *e, t_tlst **new) =
{
	NULL,
	save_str,
	save_type,
	save_type,
	save_type,
	save_type,
	NULL,
	NULL,
	save_str,
	save_str,
	save_str
};

#endif
