/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_2d_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <cybercrep@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 02:18:34 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/04 17:54:55 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_2d_fd(const int fd, const char **str)
{
	while (*str)
	{
		write(fd, *str, ft_strlen(*str));
		str++;
	}
}
