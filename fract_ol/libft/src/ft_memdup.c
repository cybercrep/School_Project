/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <cybercrep@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 00:39:46 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/11 16:15:47 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *data, size_t n)
{
	void			*out;
	unsigned char	*pt_out;
	unsigned char	*pt_data;

	if ((out = ft_memalloc(n)) == NULL)
		return (NULL);
	pt_out = (unsigned char *)out;
	pt_data = (unsigned char *)data;
	while (n)
	{
		*pt_out = *pt_data;
		pt_out++;
		pt_data++;
		n--;
	}
	return (out);
}
