/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 01:34:51 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/07 21:43:02 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_mlx(t_all *all)
{
	if ((all->pt_mlx.mlx = mlx_init()) == NULL)
		return (-1);
	if ((all->pt_mlx.win = mlx_new_window(all->pt_mlx.mlx,
					S_WIN_X, S_WIN_Y, TITLE)) == NULL)
		return (-1);
	if ((all->image.img = mlx_new_image(all->pt_mlx.mlx,
					S_WIN_X, S_WIN_Y)) == NULL)
		return (-1);
	if ((all->image.data = mlx_get_data_addr(
					all->image.img, &all->image.bpp,
					&all->image.s_line, &all->image.endian)) == NULL)
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
