/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:20 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:20 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	const char	*tmp;
	const char	*init_needle;

	init_needle = needle;
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			tmp = haystack;
			while (*haystack == *needle && *haystack)
			{
				haystack++;
				needle++;
			}
			if (*needle == '\0')
				return ((char *)tmp);
			haystack = tmp + 1;
			needle = init_needle;
		}
		haystack++;
	}
	return (NULL);
}
