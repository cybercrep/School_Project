/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:18:44 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/04 15:53:56 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncpy(char *dst, const char *src, size_t n)
{
	int i;

	i = 0;
	while (*src && n)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
		n--;
	}
	while (n != 0)
	{
		*dst = '\0';
		dst++;
		n--;
	}
	return (i);
}
