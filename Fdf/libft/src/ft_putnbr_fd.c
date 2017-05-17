/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:17:27 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/08/04 17:59:41 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(const int fd, int n)
{
	if (n == -2147483648)
	{
		ft_putstr_fd(fd, "-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd(fd, '-');
		n = -n;
	}
	if (n <= 9)
		ft_putchar_fd(fd, n + '0');
	else
	{
		ft_putnbr_fd(fd, n / 10);
		ft_putnbr_fd(fd, n % 10);
	}
}
