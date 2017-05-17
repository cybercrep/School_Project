/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 10:53:34 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/07 23:41:37 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# define PUT_ZOOM	0

# define TITLE		"FDF"
# define S_WIN_X	1000
# define S_WIN_Y	1000

# define COLOR		0xFF358B

# define ESC		53
# define RETURN		36

# define MORE		69
# define LESS		78
# define MULTI		67
# define DIVI		75

# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGH		124

# define ABS(x)		x > 0 ? x : -x;

typedef struct	s_image
{
	void		*img;
	char		*data;
	int			bpp;
	int			s_line;
	int			endian;
}				t_image;

typedef struct	s_mlx_ptr
{
	void		*mlx;
	void		*win;
}				t_mlx_ptr;

typedef struct	s_all
{
	t_mlx_ptr	pt_mlx;
	t_image		image;
	t_int2d		*map;
}				t_all;

# ifndef T_POS
#  define T_POS

typedef struct	s_pos
{
	int				x;
	int				y;
	int				z;
}				t_pos;

# endif

# ifndef T_SPOS
#  define T_SPOS

typedef struct	s_spos
{
	size_t			x;
	size_t			y;
	size_t			z;
}				t_spos;

# endif

t_int2d			*parseur(const char *path);

int				init_mlx(t_all *all);
int				init_new_img(t_all *all);
int				fdf_key_hook(int keycode, t_all *all);

void			free_all(t_all *all);

void			trace_map(t_point decale, t_point zoom, t_all *all);

void			ft_trace_seg(t_point p1, t_point p2, t_all *all);

void			change_img(int x, int y, t_all *all);

void			change_img(int x, int y, t_all *all);

void			finil_pos(t_point p1, t_point p2, t_all *all);

void			ft_putzoom(t_point *zoom);

t_int2d			*ft_new_int2d(size_t nb_line);

void			ft_putpoint(t_point point);
void			ft_putint2d_debug(t_int2d *tab);
void			ft_vswap(void *pt_1, void *pt_2);
void			ft_putint2d(t_int2d *tab);

#endif
