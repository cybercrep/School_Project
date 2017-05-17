/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:47:45 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/06 08:51:30 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*ptr_src;

	ptr_src = (unsigned char *)src;
	while (n--)
	{
		if (*ptr_src == (unsigned char)c)
			return (ptr_src);
		ptr_src++;
	}
	return (NULL);
}
