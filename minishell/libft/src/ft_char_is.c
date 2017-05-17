/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:15:48 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/04 15:19:33 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isascii(const char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int		ft_isalpha(const char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		ft_isdigit(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isprint(const char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
