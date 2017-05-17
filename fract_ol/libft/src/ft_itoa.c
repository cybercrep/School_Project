/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <cybercrep@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:21:37 by tifuzeau          #+#    #+#             */
/*   Updated: 2015/12/01 06:35:50 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_intout(int n, char *out, int len)
{
	out[len] = ((n % 10) + '0');
	if (n > 9)
		ft_intout(n / 10, out, --len);
}

char		*ft_itoa(int n)
{
	char	*out;
	int		len;

	len = ft_sizeint(n) + 1;
	out = (char *)ft_memalloc(len);
	if (n == -2147483648)
	{
		out = "-2147483648";
		return (out);
	}
	len -= 2;
	if (out)
	{
		out[len] = '\0';
		if (n < 0)
		{
			out[0] = '-';
			n = -n;
			ft_intout(n, out, len);
		}
		else
			ft_intout(n, out, len);
	}
	return (out);
}
