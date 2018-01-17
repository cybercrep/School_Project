/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:18 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:18 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*pt_dst;

	pt_dst = dst;
	while (*src && n)
	{
		*pt_dst = *src;
		pt_dst++;
		src++;
		n--;
	}
	while (n != 0)
	{
		*pt_dst = '\0';
		pt_dst++;
		n--;
	}
	return (dst);
}
