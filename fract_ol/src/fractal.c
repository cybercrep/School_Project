/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:05:21 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/11/11 03:39:28 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractal(t_all *all)
{
	int			i;
	t_point		pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < S_WIN_Y)
	{
		while (pos.x < S_WIN_X)
		{
			if (all->focus == 1)
				i = mandelbrote(pos, all->iter_max, all);
			else if (all->focus == 2)
				i = julia(pos, all->iter_max, all);
			else if (all->focus == 3)
				i = burn(pos, all->iter_max, all);
			if (i == all->iter_max)
				change_img(pos.x, pos.y, 0x000000, all);
			else
				change_img(pos.x, pos.y, all->color * i, all);
			pos.x++;
		}
		pos.y++;
		pos.x = 0;
	}
}
