/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 15:12:36 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/11/11 04:16:33 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			expose_hook(t_all *all)
{
	ft_memset(all->image.data, 0, S_WIN_X * S_WIN_Y);
	fractal(all);
	mlx_clear_window(all->pt_mlx.mlx, all->pt_mlx.win);
	mlx_put_image_to_window(all->pt_mlx.mlx,
			all->pt_mlx.win, all->image.img, 0, 0);
}

int				key_hook(int key, t_all *all)
{
	if (key == MORE)
		all->iter_max += 1;
	if (key == LESS)
		all->iter_max -= 1;
	if (key == UP)
		all->start.y -= 0.1;
	if (key == DOWN)
		all->start.y += 0.1;
	if (key == LEFT)
		all->start.x += 0.1;
	if (key == RIGH)
		all->start.x -= 0.1;
	if (key == Q)
		all->color = 0x500000;
	if (key == W)
		all->color = 0x005000;
	if (key == E)
		all->color = 0x505000;
	if (key == RETURN)
		all->mouve = (all->mouve == 1) ? 0 : 1;
	if (key == ESC)
		exit(EXIT_SUCCESS);
	expose_hook(all);
	return (1);
}
