/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reste.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 22:54:12 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 22:54:12 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		reset_pos_tab(t_point *pos_tab, int begin, int nbr_pieces)
{
	int		i;

	i = begin;
	while (i < nbr_pieces)
	{
		pos_tab[i].x = -21;
		pos_tab[i].y = -21;
		i++;
	}
}
