/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:20:50 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/28 13:38:07 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_isalpha(const char *str)
{
	while ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

int			ft_str_isdigit(const char *str)
{
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

int			ft_str_isin(const char *str, char c)
{
	if (str == NULL)
		return (-1);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
