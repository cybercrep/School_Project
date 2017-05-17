/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_size_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:48:56 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/24 05:01:09 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size__t(size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void		ft_out(size_t n, char *out)
{
	*out = ((n % 10) + '0');
	if (n > 9 && n != 0)
		ft_out(n / 10, out - 1);
}

char			*ft_itoa_size_t(size_t n)
{
	char		*out;
	size_t		len_out;

	len_out = size__t(n);
	if ((out = ft_strnew(len_out)) == NULL)
		return (NULL);
	ft_out(n, out + (len_out - 1));
	return (out);
}
