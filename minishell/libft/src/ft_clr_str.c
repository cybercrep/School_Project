/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clr_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:23:18 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/04 16:25:11 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	if (*as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

void	ft_strclr(char *str)
{
	while (*str)
	{
		*str = '\0';
		str++;
	}
}

void	ft_strnclr(char *str, size_t n)
{
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
}
