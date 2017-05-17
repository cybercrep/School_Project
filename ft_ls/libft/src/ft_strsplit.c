/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:20:23 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/03 08:57:53 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	dim_split(char *s, char c)
{
	size_t	y;

	y = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s && *s != c)
			s++;
		y++;
	}
	return (y);
}

static char		*split(char **str, char c)
{
	int			x;
	char		*out;
	char		*pt_str;
	char		*pt_out;

	pt_str = *str;
	x = ft_dim_x(*str, c) + 1;
	if ((out = ft_strnew(x)) == NULL)
		return (NULL);
	pt_out = out;
	while (*pt_str && *pt_str != c)
	{
		*pt_out = *pt_str;
		pt_out++;
		pt_str++;
	}
	*pt_out = '\0';
	*str = pt_str;
	return (out);
}

char			**ft_strsplit(char *str, char c)
{
	size_t		y;
	char		**out;
	char		**pt_out;

	y = dim_split(str, c);
	if ((out = ft_strnew_2d(y)) == NULL)
		return (NULL);
	pt_out = out;
	while (*str)
	{
		while (*str == c)
			str++;
		if (!*str)
			break ;
		*pt_out = split(&str, c);
		pt_out++;
	}
	return (out);
}
