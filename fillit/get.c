/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 22:54:10 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 22:54:10 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	get_map_from(t_square *map, t_point pos, t_point *pos_tab)
{
	int				i;
	unsigned int	env;
	t_point			tmp;

	i = -1;
	env = 0;
	tmp.x = -21;
	tmp.y = -21;
	while (++i < map->nbr_pieces && pos_tab[i].x != -21)
	{
		tmp.x = pos.x - pos_tab[i].x;
		tmp.y = pos.y - pos_tab[i].y;
		env += shift_by(map->pieces[i], tmp);
	}
	return (env);
}

int				get_square_size(t_square *map, t_point *pos_tab)
{
	int			i;
	t_point		max;
	t_point		tmp;

	i = -1;
	max.x = 1;
	max.y = 1;
	while (++i < map->nbr_pieces && pos_tab[i].x != -1)
	{
		tmp.y = -1;
		while (++tmp.y < 4)
		{
			tmp.x = -1;
			while (++tmp.x < 4)
				if (map->pieces[i] & (1 << (-tmp.x - 4 * tmp.y + 23)))
				{
					max.x = pos_tab[i].x + tmp.x + 1 > max.x ?
						pos_tab[i].x + tmp.x + 1 : max.x;
					max.y = pos_tab[i].y + tmp.y + 1 > max.y ?
						pos_tab[i].y + tmp.y + 1 : max.y;
				}
		}
	}
	return (max.x > max.y ? max.x : max.y);
}
