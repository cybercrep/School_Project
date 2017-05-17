/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:59:27 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/04 17:12:42 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	char *out;
	char *tmp;

	if ((out = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	tmp = out;
	str = &str[start];
	while (len--)
	{
		*tmp = *str;
		tmp++;
		str++;
	}
	*tmp = '\0';
	return (out);
}
