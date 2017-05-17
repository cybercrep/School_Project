/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:16:50 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/04 17:14:01 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *meule, const char *aiguille)
{
	const char	*tmp;
	const char	*init_aiguille;

	init_aiguille = aiguille;
	if (!(*aiguille))
		return ((char *)meule);
	while (*meule)
	{
		if (*meule == *aiguille)
		{
			tmp = meule;
			while (*meule == *aiguille && *meule)
			{
				meule++;
				aiguille++;
			}
			if (*aiguille == '\0')
				return ((char *)tmp);
			meule = tmp + 1;
			aiguille = init_aiguille;
		}
		meule++;
	}
	return (NULL);
}

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
