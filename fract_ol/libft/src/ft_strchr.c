/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:38:42 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/04 16:00:42 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, char c)
{
	char *out;

	out = (char *)str;
	while (*out)
	{
		if (*out == c)
			return (out);
		out++;
	}
	if (c == 0)
		return (out);
	return (NULL);
}

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
