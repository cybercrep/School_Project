/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinspace_2d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 02:52:45 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/21 16:50:54 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		lenjoin(const char **str)
{
	size_t		len;

	len = 0;
	while (*str)
	{
		len += ft_strlen(*str) + 1;
		str++;
	}
	return (len);
}

char				*ft_strjoinspace_2d(const char **str)
{
	char		*out;
	char		*pt_out;
	size_t		len;

	len = lenjoin(str);
	if ((out = ft_strnew(len)) == NULL)
		return (NULL);
	pt_out = out;
	while (*str)
	{
		pt_out += ft_strcpy(pt_out, *str);
		str++;
		*pt_out = ' ';
		pt_out++;
	}
	*(pt_out - 1) = '\0';
	return (out);
}
