/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:02:14 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/04 15:53:02 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
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
