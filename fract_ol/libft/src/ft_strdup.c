/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:34:04 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/04 16:51:22 by tifuzeau         ###   ########.fr       */
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
