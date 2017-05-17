/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 02:06:17 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/07 23:34:59 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			decale(t_point *decal, int key)
{
	if (key == RIGH)
		decal->x += 5;
	if (key == LEFT)
		decal->x -= 5;
	if (key == DOWN)
		decal->y += 5;
	if (key == UP)
		decal->y -= 5;
	if (key == 0)
	{
		decal = 0;
		decal = 0;
	}
}

static void			zoome(t_point *zoom, int key)
{
	if (key == MORE)
		zoom->x++;
	else if (key == LESS)
	{
		if ((zoom->x - 1) < 1)
			ft_putstr_fd(2, "operation non autoriser\n");
		else
			zoom->x--;
	}
	else if (key == MULTI)
		zoom->y++;
	else if (key == DIVI)
	{
		if ((zoom->y - 1) < 0)
			ft_putstr_fd(2, "operation non autoriser\n");
		else
			zoom->y--;
	}
	else if (key == 0)
	{
		zoom->x = 10;
		zoom->y = 2;
	}
}

static void			put_new(t_point decal, t_point zoom, t_all *all)
{
	mlx_clear_window(all->pt_mlx.mlx, all->pt_mlx.win);
	mlx_destroy_image(all->pt_mlx.mlx, all->image.img);
	if (init_new_img(all) == -1)
	{
		ft_putstr_fd(2, "error make new image\n");
		exit(-1);
	}
	trace_map(decal, zoom, all);
	if (PUT_ZOOM)
		ft_putzoom(&zoom);
}

int					fdf_key_hook(int key, t_all *all)
{
	static t_point		zoom = {10, 2};
	static t_point		decal = {0, 0};

	if (key == ESC)
	{
		free_all(all);
		ft_putstr("Close fdf\n");
		exit(1);
	}
	if (key == RETURN)
	{
		zoome(&zoom, 0);
		decale(&decal, 0);
	}
	if (key == MORE || key == LESS || key == MULTI || key == DIVI)
		zoome(&zoom, key);
	if (key == UP || key == DOWN || key == LEFT || key == RIGH)
		decale(&decal, key);
	put_new(decal, zoom, all);
	return (0);
}
