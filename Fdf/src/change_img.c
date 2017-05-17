/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 11:09:14 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/07 23:41:48 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_img(int x, int y, t_all *all)
{
	t_spoint		tmp;
	char			*img;

	img = all->image.data;
	if ((x >= S_WIN_X || y >= S_WIN_Y) || (x < 0 || y < 0))
		return ;
	tmp.x = x * all->image.bpp / 8;
	tmp.y = y * all->image.s_line;
	img += tmp.x + tmp.y;
	*(unsigned int *)img = COLOR;
}
