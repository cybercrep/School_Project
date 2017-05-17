/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:20:23 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/03 09:02:18 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	dim_split(char const *s, char c)
{
	size_t	y;

	y = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
			s++;
		y++;
	}
	return (y);
}

static char		*split(char const *str, char c, int *pt_i)
{
	int			x;
	int			i;
	char		*out;
	char		*pt_out;

	i = *pt_i;
	x = ft_dim_x(&str[i], c) + 1;
	if ((out = ft_strnew(x)) == NULL)
		return (NULL);
	pt_out = out;
	while (str[i] != c && str[i])
	{
		*pt_out = str[i];
		pt_out++;
		i++;
	}
	*pt_out = '\0';
	*pt_i = i;
	return (out);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	size_t		j;
	size_t		y;
	char		**out;

	i = 0;
	j = 0;
	y = dim_split(s, c);
	out = (char **)malloc(sizeof(char **) * y);
	if (!out)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			out[j++] = split(s, c, &i);
	}
	out[j] = NULL;
	return (out);
}
