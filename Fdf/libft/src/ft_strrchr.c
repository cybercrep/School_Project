/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:50:19 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/04 16:33:14 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	char		*out;
	size_t		len_s;

	len_s = ft_strlen(str) + 1;
	out = (char *)str + len_s - 1;
	while (len_s != 0)
	{
		if (*out == c)
			return (out);
		out--;
		len_s--;
	}
	return (NULL);
}
