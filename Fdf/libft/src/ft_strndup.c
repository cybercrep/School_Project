/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:11:46 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/04 17:08:14 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*out;
	char		*tmp;
	size_t		len_max;

	len_max = ft_strlen(s1);
	if (len_max > n)
		len_max = n;
	if ((out = (char *)malloc(sizeof(char) * (len_max + 1))) == NULL)
		return (NULL);
	tmp = out;
	while (*s1 && n)
	{
		*out = *s1;
		out++;
		s1++;
		n--;
	}
	*out = '\0';
	return (tmp);
}
