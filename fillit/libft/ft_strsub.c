/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:20 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:20 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char *out;
	char *tmp;

	if (str == NULL)
		return (NULL);
	if ((out = ft_strnew(len)) == NULL)
		return (NULL);
	tmp = out;
	str = &str[start];
	while (len--)
	{
		*tmp = *str;
		tmp++;
		str++;
	}
	*tmp = '\0';
	return (out);
}
