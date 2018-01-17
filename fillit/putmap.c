/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   putmap.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 22:54:11 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 22:54:11 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		**filltab(char **tab, t_square *map, t_point *pos_tab)
{
	int		num_piece;
	int		cpt_line;
	int		cpt_col;

	num_piece = -1;
	while (++num_piece < map->nbr_pieces && pos_tab[num_piece].x != -42)
	{
		cpt_line = -1;
		while (++cpt_line < 4)
		{
			cpt_col = -1;
			while (++cpt_col < 4)
			{
				if (map->pieces[num_piece] && map->pieces[num_piece] &
						(1 << (23 - cpt_line * 4 - cpt_col)))
				{
					if (pos_tab[num_piece].y >= 0 && pos_tab[num_piece].x >= 0)
						tab[pos_tab[num_piece].y +
							cpt_line][pos_tab[num_piece].x
							+ cpt_col] = 'A' + num_piece;
				}
			}
		}
	}
	return (tab);
}

void		putmap(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		ft_putendl(tab[i]);
		free(tab[i]);
	}
	free(tab);
}
