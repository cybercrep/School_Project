/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 03:01:42 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/06 04:08:33 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_putzoom(t_point *zoom)
{
	ft_putstr("espace entre 2 point:");
	ft_putnbr(zoom->x);
	ft_putstr("\nZ * =");
	ft_putnbr(zoom->y);
	ft_putchar('\n');
}
