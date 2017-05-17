/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 08:55:06 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/19 19:06:17 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strnew_2d(size_t len)
{
	char	**out;
	char	**pt_out;

	len++;
	if ((out = (char **)malloc(sizeof(char *) * (len))) == NULL)
		return (NULL);
	pt_out = out;
	while (len)
	{
		*pt_out = NULL;
		pt_out++;
		len--;
	}
	return (out);
}

void		ft_initstr_2d(char **str, size_t len)
{
	while (len)
	{
		*str = NULL;
		str++;
		len--;
	}
}
