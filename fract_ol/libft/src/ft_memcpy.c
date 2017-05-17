/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:53:45 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/06 08:46:46 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;

	ptr_dst = (unsigned char *)dst;
	while (n)
	{
		*ptr_dst = *((unsigned char *)(src));
		ptr_dst++;
		src++;
		n--;
	}
	return (dst);
}
