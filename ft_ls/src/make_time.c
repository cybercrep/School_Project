/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 19:33:22 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/25 00:48:11 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			make_time(t_2lst_info *mallion)
{
	char	*tmp;
	time_t	ti_tmp[3];

	if ((tmp = ctime(&mallion->st_info.st_mtime)) == NULL)
		return (-1);
	mallion->print_l[L_MON] = ft_strndup(&tmp[4], 3);
	mallion->print_l[L_DATE] = ft_strndup(&tmp[8], 2);
	ti_tmp[0] = time(NULL);
	ti_tmp[1] = ti_tmp[0] + (3600 * 24 * 30);
	ti_tmp[2] = ti_tmp[0] - (3600 * 24 * 182);
	ti_tmp[0] = mallion->st_info.st_mtime;
	if ((ti_tmp[0] > ti_tmp[1]) || (ti_tmp[0] < ti_tmp[2]))
		mallion->print_l[L_HO_YE] = ft_strndup(&tmp[20], 4);
	else
	{
		if ((mallion->print_l[L_HO_YE] = ft_strndup(&tmp[11], 5)) == NULL)
			return (-1);
	}
	return (1);
}
