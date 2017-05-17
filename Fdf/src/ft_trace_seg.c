/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_seg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 02:26:37 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/06 04:17:34 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fuck_1(t_point pos, t_point inc, t_point dir, t_all *all)
{
	int		i;
	int		x;
	int		y;
	int		cumul;

	i = 0;
	x = pos.x;
	y = pos.y;
	cumul = dir.x >> 1;
	while (i <= dir.x)
	{
		change_img(x, y, all);
		x += inc.x;
		cumul += dir.y;
		if (cumul >= dir.x)
		{
			cumul -= dir.x;
			y += inc.y;
		}
		i++;
	}
}

static void	fuck_2(t_point pos, t_point inc, t_point dir, t_all *all)
{
	int		i;
	int		x;
	int		y;
	int		cumul;

	i = 0;
	x = pos.x;
	y = pos.y;
	cumul = dir.y >> 1;
	while (i <= dir.y)
	{
		change_img(x, y, all);
		y += inc.y;
		cumul += dir.x;
		if (cumul >= dir.y)
		{
			cumul -= dir.y;
			x += inc.x;
		}
		i++;
	}
}

void		ft_trace_seg(t_point p1, t_point p2, t_all *all)
{
	t_point		pos;
	t_point		inc;
	t_point		dir;

	dir.x = p2.x - p1.x;
	dir.y = p2.y - p1.y;
	pos.x = p1.x;
	pos.y = p1.y;
	inc.x = (dir.x > 0) ? 1 : -1;
	inc.y = (dir.y > 0) ? 1 : -1;
	dir.x = ABS(dir.x);
	dir.y = ABS(dir.y);
	if (dir.x > dir.y)
		fuck_1(pos, inc, dir, all);
	else
		fuck_2(pos, inc, dir, all);
}
