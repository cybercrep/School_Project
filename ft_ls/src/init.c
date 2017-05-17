/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 04:21:49 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/21 06:17:17 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*init_droit(void)
{
	int		i;
	char	*out;
	char	rwx[3];
	char	*pt_out;

	i = 0;
	rwx[0] = 'r';
	rwx[1] = 'w';
	rwx[2] = 'x';
	if ((out = malloc(sizeof(char) * 11)) == NULL)
		fail("malloc");
	pt_out = out;
	*pt_out = '-';
	pt_out++;
	while (i != 9)
	{
		*pt_out = rwx[i % 3];
		pt_out++;
		i++;
	}
	*pt_out = '\0';
	return (out);
}
