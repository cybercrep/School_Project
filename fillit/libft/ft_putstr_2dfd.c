/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_2dfd.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:12 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:12 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_2dfd(const char **str, int fd)
{
	while (*str)
	{
		write(fd, *str, ft_strlen(*str));
		write(fd, "\n", 1);
		str++;
	}
}
