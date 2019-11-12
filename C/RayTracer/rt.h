/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquilez <jquilez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 10:01:20 by jquilez           #+#    #+#             */
/*   Updated: 2014/03/25 12:17:15 by glinford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define WIDTH 1920.0
# define HEIGHT 1080.0
# define RES 36.0
# define TITLE "RT"
# define INFO "Move Cam with W, A, S, D & Adjust Luminosity with + and -"
# define AMBIENT 0.25
# define VPW (0.60 * WIDTH) / 1920.0
# define VPH (0.35 * HEIGHT) / 1080.0
# define VPD 1.0

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_quad
{
	double			a;
	double			b;
	double			c;
	double			d;
	double			e;
	double			f;
	double			g;
	double			h;
	double			i;
	double			j;
}					t_quad;

typedef struct		s_sphere
{
	double			radius;
	t_point			origin;
}					t_sphere;

typedef struct		s_plane
{
	t_point			origin;
	t_point			equation;
	double			cst;
}					t_plane;

typedef struct		s_lst
{
	t_color			ocolor;
	double			shine;
	t_sphere		*sphere;
	t_plane			*plane;
	t_quad			*quad;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_light
{
	t_point			origin;
	t_point			vec;
	t_color			color;
}					t_light;

typedef struct		s_llst
{
	t_light			light;
	struct s_llst	*next;
}					t_llst;

typedef struct		s_cam
{
	t_point			origin;
	t_point			dir;
	t_point			vecdir;
	t_point			upleft;
	t_point			upvec;
	t_point			rightvec;
	t_point			indent;
}					t_cam;

typedef struct		s_calc
{
	double			dist;
	double			t;
	double			t1;
	double			t2;
	double			delta;
	double			a;
	double			b;
	double			c;
	double			ambient;
	t_point			inter;
	struct s_color	*all_color;
	struct s_color	*color;
}					t_calc;

typedef struct		s_env
{
	void			*mlx;
	void			*window;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	struct s_cam	*cam;
	struct s_lst	*list;
	t_llst			*light;
	struct s_calc	*calc;
	double			o_x;
	double			o_y;
	double			x;
	double			y;
}					t_env;

void		ft_error(char *file, int opt);
int			ft_parse_map(char *map, t_env **env);
char		**ft_parse_error(char **line, char ***tab);
char		**ft_parse_tab(int fd, int size, const char *name);
int			ft_parse_cam(t_env **env, int fd);
int			ft_parse_light(t_env **env, int fd);
int			ft_parse_sphere(t_env **env, int fd);
int			ft_parse_plane(t_env **env, int fd);
int			ft_parse_quad(t_env **env, int fd);
void		ft_calc_cam(t_env *env);
t_lst		*ft_listadd(t_lst *list, t_lst *add);
t_lst		*ft_listnew(int opt);
t_llst		*ft_llistadd(t_llst *list, t_llst *add);
t_llst		*ft_llistnew(void);
void		ft_init(t_env *env);
void		ft_pixel_put_img(t_env *env, t_color *color, int x, int y);
void		ft_scene(t_env *env);
void		ft_load(t_env *env);
void		ft_light(t_env *env, t_lst *lst);
int			ft_shadow(t_env *env, t_lst *lst, t_light light);
double		ft_dist(t_env *env, t_lst *lst, t_point dir, t_point org);
t_point		ft_vecmult(t_point p, double d);
double		ft_dotprod(t_point a, t_point b);
void		ft_crossprod(t_point a, t_point b, t_point *res);
void		ft_normalize(t_point *p);
double		ft_sphere(t_env *env, t_lst *lst, t_point dir, t_point org);
double		ft_plane(t_env *env, t_lst *lst, t_point dir, t_point org);
double		ft_quad(t_quad q, t_point d, t_point o);
char		**ft_split(char const *s);

#endif
