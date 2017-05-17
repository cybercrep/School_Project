/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:34:04 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/04/05 17:23:12 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*out;
	char			*tmp;

	if ((out = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	tmp = out;
	while (*s1)
	{
		*out = *s1;
		out++;
		s1++;
	}
	*out = '\0';
	return (tmp);
}
