/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:21:03 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/11/11 04:19:06 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
********************************************************************************
**								INCLUDES                                      **
********************************************************************************
*/

# include "libft.h"
# include <mlx.h>
# include <stdlib.h>

/*
********************************************************************************
**								DEFINE                                        **
********************************************************************************
*/

# define ABS(x) x > 0 ? x : -x

/*
** window
*/
# define TITLE		"Fract'ol"
# define S_WIN_X	500
# define S_WIN_Y	500

/*
** key code
*/
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

# define Q			12
# define W			13
# define E			14

/*
**	Usage
*/
# define USAGE		"Fract'ol\nUsage: fractol -m -j -b\n"

/*
********************************************************************************
**								STRUT                                     **
********************************************************************************
*/

/*
**							for mlx
*/
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
/*
**							autre
*/
typedef struct	s_dpoint
{
	double		x;
	double		y;
}				t_dpoint;

typedef struct	s_complex
{
	long double	r;
	long double	i;
}				t_complex;

/*
**							struct general
*/

typedef struct	s_all
{
	t_mlx_ptr		pt_mlx;
	t_image			image;
	t_dpoint		origine;
	t_dpoint		start;
	t_point			pos_mouse;
	unsigned int	color;
	int				zoom;
	int				iter_max;
	int				focus;
	int				mouve;
}				t_all;

/*
********************************************************************************
**								FONCTIONS                                     **
********************************************************************************
*/

/*
**						MLX
*/

/*
**	in init.c
*/
int				init_mlx(t_all *all);
int				init_new_img(t_all *all);
int				init_all(t_all *all);
/*
**	in change_img.h
*/
void			change_img(int x, int y, unsigned int color, t_all *all);

/*
**						HOOK
*/

/*
**	in hook.c
*/
void			expose_hook(t_all *all);
int				key_hook(int key, t_all *all);

/*
**	in mouse_hook.c
*/
int				mouse_hook(int button, int x, int y, t_all *all);
int				mouse_pos(int x, int y, t_all *all);

/*
**						Fractal
*/

/*
**	in fractal.c
*/
void			fractal(t_all *all);

/*
**	in formule.c
*/
int				julia(t_point pos, int iter_max, t_all *all);
int				mandelbrote(t_point pos, int iter_max, t_all *all);
int				burn(t_point pos, int iter_max, t_all *all);
/*
**						Autre
*/

/*
**	in put_usage.c
*/
void			put_usage(void);

/*
**	in parseur.c
*/
void			parseur(const char **argv, t_all *all);

#endif
