/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_2d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:10 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:10 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_2d(const char **str)
{
	while (*str)
	{
		write(1, *str, ft_strlen(*str));
		write(1, "\n", 1);
		str++;
	}
}
