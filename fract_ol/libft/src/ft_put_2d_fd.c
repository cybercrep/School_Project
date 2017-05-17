/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_2d_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:06:38 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/04 16:06:42 by tifuzeau         ###   ########.fr       */
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
