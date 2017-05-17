/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 08:55:06 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/03 08:56:47 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strnew_2d(size_t len)
{
	char	**out;

	if ((out = (char **)malloc(sizeof(char *) * len)) == NULL)
		return (NULL);
	while (len)
	{
		*out = NULL;
		out++;
	}
	return (out);
}
