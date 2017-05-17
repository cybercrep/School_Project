/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 01:07:56 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/07 06:12:30 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point		gen_pos(t_spoint pos,
		t_point decal, t_point zoom, t_int2d *map)
{
	t_point		out;

	pos.x += pos.y;
	out.x = ((S_WIN_X >> 1) - ((map->nb_by_line[pos.y] >> 1) - pos.x) * zoom.x);
	out.y = ((S_WIN_Y >> 1) - ((map->nb_line >> 1) - pos.y) * zoom.x);
	out.y -= map->tab[pos.y][pos.x - pos.y] * zoom.y;
	out.x += decal.x;
	out.y += decal.y;
	return (out);
}

static void			call_point(t_spoint pos,
		t_point decal, t_point zoom, t_all *all)
{
	t_point		p1;
	t_point		p2;

	p1 = gen_pos(pos, decal, zoom, all->map);
	if (pos.x + 1 < all->map->nb_by_line[pos.y])
	{
		pos.x++;
		p2 = gen_pos(pos, decal, zoom, all->map);
		finil_pos(p1, p2, all);
		pos.x--;
	}
	if (pos.y + 1 < all->map->nb_line)
	{
		pos.y++;
		p2 = gen_pos(pos, decal, zoom, all->map);
		finil_pos(p1, p2, all);
		pos.y--;
	}
}

void				trace_map(t_point decal, t_point zoom, t_all *all)
{
	t_spoint	pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < all->map->nb_line)
	{
		while (pos.x < all->map->nb_by_line[pos.y])
		{
			call_point(pos, decal, zoom, all);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	mlx_put_image_to_window(all->pt_mlx.mlx, all->pt_mlx.win,
			all->image.img, 0, 0);
}
