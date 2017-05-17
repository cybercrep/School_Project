/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:36:43 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/04 17:59:59 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncat(char *dst, const char *src, size_t n)
{
	int		i;

	i = 0;
	while (*dst != '\0')
		dst++;
	while (*src && n)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
		i++;
	}
	*dst = '\0';
	return (i);
}
