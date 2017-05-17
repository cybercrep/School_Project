/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_one_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 06:54:29 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/11 21:14:37 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	add_space(char **str, size_t size)
{
	char	*tmp;

	tmp = *str;
	while (size != 0)
	{
		*tmp = ' ';
		tmp++;
		size--;
	}
	*str = tmp;
}

static void	cpy_space(char **dst, const char *src, size_t size)
{
	char	*tmp;

	tmp = *dst;
	while (*src && size > 0)
	{
		*tmp = *src;
		size--;
		tmp++;
		src++;
	}
	*dst = tmp;
	if (size != 0)
		add_space(dst, size);
}

char		*ft_strjoin_one_size(const char **str, size_t *size_max, size_t len)
{
	char	*out;
	char	*pt_out;
	size_t	len_out;

	len_out = ft_size_t_addtab(size_max, len);
	len_out += 2 * len;
	if ((out = ft_strnew(len_out)) == NULL)
		return (NULL);
	pt_out = out;
	while (len != 0)
	{
		if (*str == NULL)
			add_space(&pt_out, *size_max);
		else
			cpy_space(&pt_out, *str, *size_max);
		add_space(&pt_out, 1);
		size_max++;
		str++;
		len--;
	}
	return (out);
}
