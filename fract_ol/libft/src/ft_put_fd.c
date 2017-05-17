/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:51:44 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/04 15:58:49 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putchar_fd(const int fd, const char c)
{
	return (write(fd, &c, 1));
}

ssize_t		ft_putstr_fd(const int fd, const char *str)
{
	return (write(fd, str, ft_strlen(str)));
}

ssize_t		ft_putendl_fd(const int fd, const char *str)
{
	ssize_t i;

	i = write(fd, str, ft_strlen(str));
	ft_putchar_fd(fd, '\n');
	return (i + 1);
}

void		ft_putnbr_fd(const int fd, int n)
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
