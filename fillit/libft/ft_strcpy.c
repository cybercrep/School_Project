/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:14 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:14 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	char	*pt_dst;

	pt_dst = dst;
	while (*src)
	{
		*pt_dst = *src;
		pt_dst++;
		src++;
	}
	*pt_dst = '\0';
	return (dst);
}
