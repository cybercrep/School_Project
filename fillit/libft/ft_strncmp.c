/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:18 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:18 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char *pt_s1;
	char *pt_s2;

	if (n == 0)
		return (0);
	pt_s1 = (char *)s1;
	pt_s2 = (char *)s2;
	while (*pt_s1 && (*pt_s1 == *pt_s2) && n > 1)
	{
		pt_s1++;
		pt_s2++;
		n--;
	}
	return ((unsigned char)*pt_s1 - (unsigned char)*pt_s2);
}
