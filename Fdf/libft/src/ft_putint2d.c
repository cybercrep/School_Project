/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 00:26:08 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/07 03:50:10 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putint2d(t_int2d *tab)
{
	t_spoint		pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < tab->nb_line)
	{
		while (pos.x < tab->nb_by_line[pos.y])
		{
			ft_putnbr(tab->tab[pos.y][pos.x]);
			ft_putchar(' ');
			pos.x++;
		}
		ft_putchar('\n');
		pos.x = 0;
		pos.y++;
	}
}

void		ft_putint2d_debug(t_int2d *tab)
{
	t_spoint		pos;

	pos.x = 0;
	pos.y = 0;
	ft_putstr("nb_line=");
	ft_putnbr(tab->nb_line);
	ft_putchar('\n');
	while (pos.y < tab->nb_line)
	{
		ft_putstr("nb_by_line=");
		ft_putnbr(tab->nb_by_line[pos.y]);
		ft_putstr("  y=");
		ft_putnbr(pos.y);
		ft_putchar('\t');
		while (pos.x < tab->nb_by_line[pos.y])
		{
			ft_putnbr(tab->tab[pos.y][pos.x]);
			ft_putchar(' ');
			pos.x++;
		}
		ft_putchar('\n');
		pos.x = 0;
		pos.y++;
	}
}
