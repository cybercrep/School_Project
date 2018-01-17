/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:19 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:19 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	char		*out;
	size_t		len_s;

	len_s = ft_strlen(str) + 1;
	out = (char *)str + len_s - 1;
	while (len_s != 0)
	{
		if (*out == c)
			return (out);
		out--;
		len_s--;
	}
	return (NULL);
}
