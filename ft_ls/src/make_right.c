/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   droit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 02:52:39 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/21 04:16:28 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		type(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		return ('-');
	if (S_ISDIR(st_mode))
		return ('d');
	if (S_ISLNK(st_mode))
		return ('l');
	if (S_ISCHR(st_mode))
		return ('c');
	if (S_ISBLK(st_mode))
		return ('b');
	else
		return ('?');
}

int				make_right(t_2lst_info *mallion)
{
	char			*out;
	char			*pt_out;
	unsigned int	test;

	test = 256;
	if ((out = init_droit()) == NULL)
		return (-1);
	pt_out = out;
	*pt_out = type(mallion->st_info.st_mode);
	pt_out++;
	while (test)
	{
		if (!(mallion->st_info.st_mode & test))
			*pt_out = '-';
		pt_out++;
		test = test >> 1;
	}
	mallion->print_l[L_RIGHT] = out;
	return (1);
}
