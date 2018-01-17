/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strequ_2d.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:15 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:15 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ_2d(const char **s1, const char **s2)
{
	while (*s1 && *s2)
	{
		if (ft_strequ(*s1, *s2) != 1)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 == NULL && *s2 == NULL)
		return (1);
	return (0);
}
