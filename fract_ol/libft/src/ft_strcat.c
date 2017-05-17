/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:29:28 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/04 17:03:46 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcat(char *dst, const char *src)
{
	int i;

	i = 0;
	while (*dst != '\0')
		dst++;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (i);
}

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
