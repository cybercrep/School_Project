/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 06:19:00 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/03 06:21:46 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d_size(char **str, size_t len)
{
	while (len)
	{
		if (*str != NULL)
			free(*str);
		*str = NULL;
		str++;
		len--;
	}
}
