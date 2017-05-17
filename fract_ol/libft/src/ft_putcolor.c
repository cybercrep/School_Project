/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 18:07:57 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/19 18:45:44 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

void		ft_putcolor(const char *str, const char *color)
{
	if (color != NULL)
		write(1, color, ft_strlen(color));
	if (str != NULL)
		write(1, str, ft_strlen(str));
	write(1, C_RESET, 4);
}
