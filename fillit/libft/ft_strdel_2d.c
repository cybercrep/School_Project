/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdel_2d.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:14 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:14 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_strdel_2d(char ***as)
{
	char	**str;

	str = *as;
	while (*str != NULL)
	{
		free(*str);
		*str = NULL;
		str++;
	}
	free(*as);
	*as = NULL;
}
