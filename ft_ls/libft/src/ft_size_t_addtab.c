/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_t_addtab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 08:00:37 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/02 08:04:04 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_size_t_addtab(const size_t *tab, size_t len)
{
	size_t		out;

	out = 0;
	while (len != 0)
	{
		out += *tab;
		tab++;
		len--;
	}
	return (out);
}
