/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 01:20:43 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/06 04:07:12 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putpoint(t_point point)
{
	ft_putstr("x=");
	ft_putnbr(point.x);
	ft_putstr("\t,y=");
	ft_putnbr(point.y);
	ft_putchar('\n');
}
