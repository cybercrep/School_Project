/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:59:27 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/01 06:18:45 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *out;
	char *tmp;

	if ((out = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	tmp = out;
	s = &s[start];
	while (len--)
	{
		*tmp = *s;
		tmp++;
		s++;
	}
	*tmp = '\0';
	return (out);
}
