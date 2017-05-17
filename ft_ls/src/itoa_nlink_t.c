/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_off_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 04:17:19 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/16 01:37:00 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	size_off(nlink_t n)
{
	size_t		i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i - 1);
}

static void		ft_out(nlink_t n, char *out)
{
	*out = ((n % 10) + '0');
	if (n > 9 && n != 0)
		ft_out(n / 10, out - 1);
}

char			*itoa_nlink_t(nlink_t n)
{
	char		*out;
	size_t		len_out;

	len_out = size_off(n);
	if ((out = ft_strnew(len_out)) == NULL)
		return (NULL);
	ft_out(n, out + len_out);
	return (out);
}
