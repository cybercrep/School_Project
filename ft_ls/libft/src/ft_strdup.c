/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:34:04 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/03/28 18:45:34 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	register char	*out;
	char			*tmp;

	if ((out = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
		return (NULL);
	tmp = out;
	while (*str)
	{
		*out = *str;
		out++;
		str++;
	}
	*out = '\0';
	return (tmp);
}
