/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:01:59 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/19 18:57:51 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_2d(const char **str)
{
	while (*str)
	{
		write(1, *str, ft_strlen(*str));
		ft_putchar('\n');
		str++;
	}
}

void	ft_putendl_2d(const char **str)
{
	while (*str)
	{
		write(1, *str, ft_strlen(*str));
		write(1, "\n", 1);
		str++;
	}
}
