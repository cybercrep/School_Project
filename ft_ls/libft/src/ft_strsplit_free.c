/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:20:23 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/03 07:55:52 by tifuzeau         ###   ########.fr       */
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

char			**ft_strsplit_free(char **as, char c)
{
	size_t		y;
	char		*pt_as;
	char		**out;
	char		**pt_out;

	pt_as = *as;
	y = dim_split(pt_as, c);
	if ((out = (char **)malloc(sizeof(char *) * y)) == NULL)
		return (NULL);
	pt_out = out;
	while (*pt_as)
	{
		while (*pt_as == c)
			pt_as++;
		if (!*pt_as)
			break ;
		*pt_out = split(&pt_as, c);
		pt_out++;
	}
	pt_out = NULL;
	free(*as);
	*as = NULL;
	return (out);
}
