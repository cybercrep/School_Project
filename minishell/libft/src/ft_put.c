/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:38:40 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/04 15:49:39 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

ssize_t		ft_putstr(const char *str)
{
	return (write(1, str, ft_strlen(str)));
}

ssize_t		ft_putendl(const char *str)
{
	ssize_t		i;

	i = write(1, str, ft_strlen(str));
	ft_putchar('\n');
	return (i + 1);
}

void		ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
