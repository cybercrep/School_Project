/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shift_bit.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 22:54:12 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 22:54:12 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

unsigned int		shift_up(unsigned int pieces)
{
	return ((pieces << 4) & 0xFFFF00);
}

unsigned int		shift_down(unsigned int pieces)
{
	return ((pieces >> 4) & 0xFFFF00);
}

unsigned int		shift_left(unsigned int pieces)
{
	return ((pieces << 1) & 0xEEEE00);
}

unsigned int		shift_right(unsigned int pieces)
{
	return ((pieces >> 1) & 0x777700);
}

unsigned int		shift_by(unsigned int pieces, t_point pos)
{
	if (pos.x < 0)
		while (pos.x++)
			pieces = shift_right(pieces);
	else if (pos.x > 0)
		while (pos.x--)
			pieces = shift_left(pieces);
	if (pos.y < 0)
		while (pos.y++)
			pieces = shift_down(pieces);
	else if (pos.y > 0)
		while (pos.y--)
			pieces = shift_up(pieces);
	return (pieces);
}
