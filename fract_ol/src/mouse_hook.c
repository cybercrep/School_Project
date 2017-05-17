/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:50:39 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/11/11 03:33:01 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int i, t_all *all)
{
	if (i)
		all->zoom += 1;
	else if (all->zoom > 1)
		all->zoom = all->zoom - (((all->zoom / 100) - 1) * 10);
}

int		mouse_hook(int button, int x, int y, t_all *all)
{
	if (button == 1 || button == 5)
	{
		all->start.x = (x - all->origine.x) / (all->zoom * all->origine.x)
			+ all->start.x;
		all->start.y = (y - all->origine.y) / (all->zoom * all->origine.y)
			+ all->start.y;
		zoom(1, all);
	}
	if ((button == 2 || button == 4) && all->zoom > 1)
	{
		all->start.x = (x - all->origine.x) / (all->zoom * all->origine.x)
			+ all->start.x;
		all->start.y = (y - all->origine.y) / (all->zoom * all->origine.y)
			+ all->start.y;
		zoom(0, all);
	}
	expose_hook(all);
	return (1);
}

int		mouse_pos(int x, int y, t_all *all)
{
	if (all->mouve)
	{
		all->pos_mouse.x = x;
		all->pos_mouse.y = y;
	}
	if (all->focus == 2)
		expose_hook(all);
	return (1);
}
