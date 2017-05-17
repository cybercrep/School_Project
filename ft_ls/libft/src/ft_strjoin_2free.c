/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:04:50 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/01 05:49:03 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_2free(char **s1, char **s2)
{
	char	*out;
	size_t	len_out;

	len_out = ft_strlen(*s1) + ft_strlen(*s2) + 1;
	if ((out = ft_strnew(len_out)) == NULL)
		return (NULL);
	if (len_out == 1)
		out[0] = '\0';
	if (*s1 != NULL)
	{
		ft_strcpy(out, *s1);
		free(*s1);
		*s1 = NULL;
	}
	if (*s2 != NULL)
	{
		ft_strcat(out, *s2);
		free(*s2);
		*s2 = NULL;
	}
	return (out);
}
