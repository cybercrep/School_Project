/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:02:14 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/11 18:07:40 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strcpy(char *dst, const char *src)
{
	size_t		size;

	size = 0;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
		size++;
	}
	*dst = '\0';
	return (size);
}
