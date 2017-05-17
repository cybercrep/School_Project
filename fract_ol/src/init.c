/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 01:34:51 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/11/11 04:15:11 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_mlx(t_all *all)
{
	if ((all->pt_mlx.mlx = mlx_init()) == NULL)
		return (-1);
	if ((all->pt_mlx.win = mlx_new_window(all->pt_mlx.mlx,
					S_WIN_X, S_WIN_Y, TITLE)) == NULL)
		return (-1);
	return (1);
}

int		init_new_img(t_all *all)
{
	if ((all->image.img = mlx_new_image(all->pt_mlx.mlx,
					S_WIN_X, S_WIN_Y)) == NULL)
		return (-1);
	if ((all->image.data = mlx_get_data_addr(
					all->image.img, &all->image.bpp,
					&all->image.s_line, &all->image.endian)) == NULL)
		return (-1);
	return (1);
}

int		init_all(t_all *all)
{
	if (init_mlx(all) == -1)
		return (-1);
	if (init_new_img(all) == -1)
		return (-1);
	all->origine.x = S_WIN_X / 2;
	all->origine.y = S_WIN_Y / 2;
	all->zoom = 1;
	all->iter_max = 50;
	all->mouve = 1;
	all->pos_mouse.x = 0;
	all->pos_mouse.y = 0;
	all->start.x = 0.0;
	all->start.y = 0.0;
	all->color = 0x500000;
	return (1);
}
