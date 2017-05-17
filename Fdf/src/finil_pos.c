/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_seg.1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 22:23:12 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/06 04:18:35 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		finil_pos(t_point p1, t_point p2, t_all *all)
{
	if ((p1.x < 0 && p2.x < 0) || (p1.y < 0 && p2.y < 0))
		return ;
	else if ((p1.x > S_WIN_X && p2.x > S_WIN_Y)
			|| (p1.y > S_WIN_X && p2.y > S_WIN_Y))
		return ;
	ft_trace_seg(p1, p2, all);
}
