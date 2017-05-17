/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:05:21 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/11/11 03:32:24 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia(t_point pos, int iter_max, t_all *all)
{
	t_complex	z;
	t_complex	z2;
	t_complex	c;
	double		tmp;
	int			iter;

	iter = 0;
	z.r = (pos.x - all->origine.x) / (all->zoom * all->origine.x)
		+ all->start.x;
	z.i = (pos.y - all->origine.y) / (all->zoom * all->origine.y)
		+ all->start.y;
	c.r = (all->pos_mouse.x - all->origine.x) / (all->origine.x);
	c.i = (all->pos_mouse.y - all->origine.y) / (all->origine.y);
	z2.r = z.r * z.r;
	z2.i = z.i * z.i;
	while ((z2.r + z2.i) < 2.0 && iter < iter_max)
	{
		tmp = z.r;
		z.r = z2.r - z2.i + c.r;
		z.i = 2 * tmp * z.i + c.i;
		z2.r = z.r * z.r;
		z2.i = z.i * z.i;
		iter++;
	}
	return (iter);
}

int			mandelbrote(t_point pos, int iter_max, t_all *all)
{
	t_complex	z;
	t_complex	z2;
	t_complex	c;
	double		tmp;
	int			iter;

	iter = 0;
	z2.r = 0;
	z2.i = 0;
	z.r = 0;
	z.i = 0;
	c.r = (pos.x - all->origine.x) / (0.5 * all->zoom * all->origine.x)
		+ all->start.x;
	c.i = (pos.y - all->origine.y) / (0.5 * all->zoom * all->origine.y)
		+ all->start.y;
	while ((z2.r + z2.i) < 4.0 && iter < iter_max)
	{
		tmp = z.r;
		z.r = z2.r - z2.i + c.r;
		z.i = 2 * tmp * z.i + c.i;
		z2.r = z.r * z.r;
		z2.i = z.i * z.i;
		iter++;
	}
	return (iter);
}

int			burn(t_point pos, int iter_max, t_all *all)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			iter;

	iter = 0;
	z.r = 0;
	z.i = 0;
	c.r = (pos.x - all->origine.x) / (0.5 * all->zoom * all->origine.x)
		+ all->start.x;
	c.i = (pos.y - all->origine.y) / (0.5 * all->zoom * all->origine.y)
		+ all->start.y;
	while ((z.r * z.r + z.i * z.i) < 4.0 && iter < iter_max)
	{
		tmp = ABS(z.r);
		z.r = ABS(z.r);
		z.i = ABS(z.i);
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = 2 * tmp * z.i + c.i;
		iter++;
	}
	return (iter);
}
