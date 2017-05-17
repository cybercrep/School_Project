/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:16:15 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/27 20:59:02 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strdel_2d(char ***as)
{
	char	**str;

	str = *as;
	while (*str != NULL)
	{
		free(*str);
		*str = NULL;
		str++;
	}
	free(*as);
	*as = NULL;
}
