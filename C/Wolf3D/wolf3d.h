/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaudot <rbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 01:57:33 by rbaudot           #+#    #+#             */
/*   Updated: 2014/01/19 23:13:15 by rbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUF 32
# define MAP "default.map"
# define HEIGHT 640
# define WIDTH 960
# define CAM_X 5
# define CAM_Y 5
# define EYE_X -1
# define EYE_Y 0
# define PLN_X 0
# define PLN_Y 0.66
# define MSPD 1
# define RSPD M_PI_2

extern const int	tab[20][20];

typedef enum		e_color
{
	RED = 16711680,
	GREEN = 65280,
	BLUE = 255,
	YELLOW = 16776960
}					t_color;

typedef struct		s_point
{
	double	x;
	double	y;
}					t_point;

typedef struct		s_img
{
	void	*i;
	int		b;
	int		s;
	int		n;
	char	*m;
}					t_img;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_point	cam;
	t_point	eye;
	t_point	pln;
}					t_env;

/*
** WOLF3D_C
*/

void	ft_exit(t_env e, int nb);
int		ft_error(char *str, void (*f)(const char *));

/*
** FT_FILE_SPLIT_C
*/

int		ft_file_split(int const fd, char ***res);

/*
** FT_DISPLAY_C
*/

int		ft_display_file(void);

/*
** FT_DRAW_C
*/

void	ft_draw(t_env e);

/*
** FT_DRAW_C
*/

double	ft_wall(int i, t_env e, int *sid, int *stp);

#endif
