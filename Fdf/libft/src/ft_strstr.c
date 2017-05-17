/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:16:50 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/04 16:37:55 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule, const char *aiguille)
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
