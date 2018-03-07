/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 22:54:09 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 22:54:09 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	collides(t_square *map, unsigned int pieces, t_point pos, t_point *pos_tab)
{
	return (get_map_from(map, pos, pos_tab) & pieces);
}

int	put_pieces(t_square *map, t_point *pos_tab, int num_pieces, int skip)
{
	t_point		pos;
	int			tmp;

	pos.y = -1;
	while (++pos.y < (map->size_mini))
	{
		pos.x = -1;
		while (++pos.x >= 0)
			if ((tmp = collides(map, map->pieces[num_pieces], pos, pos_tab)))
				continue;
			else
			{
				pos_tab[num_pieces] = pos;
				if (get_square_size(map, pos_tab) > map->size_mini)
				{
					reset_pos_tab(pos_tab, num_pieces, map->nbr_pieces);
					break ;
				}
				if (num_pieces == (map->nbr_pieces - 1) || skip == 0)
					return (1);
				skip--;
				reset_pos_tab(pos_tab, num_pieces, map->nbr_pieces);
			}
	}
	return (0);
}

int	solve(t_square *map, t_point *pos_tab, int num_pieces, int skip)
{
	if (put_pieces(map, pos_tab, num_pieces, skip))
	{
		if (num_pieces + 1 == map->nbr_pieces)
			return (1);
		else if (solve(map, pos_tab, num_pieces + 1, 0))
			return (1);
		reset_pos_tab(pos_tab, num_pieces, map->nbr_pieces);
		return (solve(map, pos_tab, num_pieces, skip + 1));
	}
	return (0);
}
