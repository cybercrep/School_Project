/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gentabint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 12:38:24 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/07 23:22:46 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		atoi_next(const char *str, int *nb)
{
	int		i;
	int		bol;
	int		out;

	i = 0;
	bol = 0;
	out = 0;
	if (*str == '-')
	{
		bol = 1;
		i++;
		str++;
	}
	while (ft_isdigit(*str))
	{
		out *= 10;
		out += *str - '0';
		str++;
		i++;
	}
	if (*str && *str != ' ')
		return (-1);
	*nb = (bol) ? -out : out;
	return (*str == '\0') ? 0 : i;
}

int				*ft_gentabint(const char *str, size_t *nb_by_line, int i)
{
	int		nb;
	int		ret;
	int		*out;

	while (*str == ' ')
		str++;
	if ((ret = atoi_next(str, &nb)) == -1)
		return (NULL);
	str += ret;
	if (ret == 0)
	{
		out = malloc(sizeof(int) * (i + 1));
		*nb_by_line = i + 1;
	}
	else
		out = ft_gentabint(str, nb_by_line, (i + 1));
	if (out == NULL)
		return (NULL);
	out[i] = nb;
	return (out);
}
