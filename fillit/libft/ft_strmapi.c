/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:17 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:17 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	char			*pt_out;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = ft_strlen(s);
	if ((out = ft_strnew(i)) == NULL)
		return (NULL);
	pt_out = out;
	i = 0;
	while (*s)
	{
		*pt_out = f(i, *s);
		pt_out++;
		s++;
		i++;
	}
	return (out);
}
