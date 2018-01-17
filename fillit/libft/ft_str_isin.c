/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_isin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:13 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:13 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

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
