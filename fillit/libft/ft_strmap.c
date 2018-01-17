/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:17 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:17 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char		*out;
	char		*pt_out;
	size_t		len;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	if ((out = ft_strnew(len)) == NULL)
		return (NULL);
	pt_out = out;
	while (*s)
	{
		*pt_out = (*f)(*s);
		pt_out++;
		s++;
	}
	return (out);
}
