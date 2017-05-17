/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:42:18 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/04 16:57:45 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		match(const char *meule, const char *aiguille, size_t n)
{
	while (n && (*aiguille && *meule) && (*meule == *aiguille))
	{
		meule++;
		aiguille++;
		n--;
	}
	if (*aiguille == '\0')
		return (1);
	else if (n == 0)
		return (-1);
	else
		return (0);
}

char			*ft_strnstr(const char *meule, const char *aiguille, size_t n)
{
	int				i;

	i = 0;
	if (!*aiguille)
		return ((char *)meule);
	while (*meule && n)
	{
		if (*meule == *aiguille)
		{
			i = match(meule, aiguille, n);
			if (i == 1)
				return ((char *)meule);
			if (i == -1)
				return (NULL);
		}
		meule++;
		n--;
	}
	return (NULL);
}
