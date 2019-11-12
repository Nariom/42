/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 11:00:26 by rbaudot           #+#    #+#             */
/*   Updated: 2013/12/23 18:21:58 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft/libft.h"
# define BUF 32
# define H 1000
# define DH 9
# define W 2000
# define DW 3
# define X 15
# define Y 10
# define Z 5
# define COL 0xFF0000

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	char		**s;
}				t_env;

typedef struct	s_point
{
	float		x;
	float		y;
	float		h;
}				t_point;

/*
** FDF
*/
int		ft_error(char *str);
/*
** FT_FILE_SPLIT
*/
int		ft_file_split(int const fd, char ***res);
/*
** FT_DISPLAY_FILE
*/
int		ft_display_file(char **split);
/*
** FT_DRAW
*/
void	ft_draw(t_env e);
/*
** FT_UTILITIES
*/
char	**ft_strsplit_spc(char *s);
float	ft_abs(float n);
void	ft_ptrstrdel(char **s);
int		ft_ptrstrlen(char **s);

#endif
