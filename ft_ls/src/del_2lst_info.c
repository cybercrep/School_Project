/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_2lst_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 20:00:30 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/29 02:05:45 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		del_2lst_info(t_2lst_info **as)
{
	t_2lst_info		*tmp;
	t_2lst_info		*tmp_next;

	tmp = *as;
	while (tmp != NULL)
	{
		tmp_next = tmp->next;
		if (tmp->path != NULL)
			ft_strdel(&tmp->path);
		ft_free_2d_size(&tmp->print_l[0], MAX_ELEM);
		free(tmp);
		tmp = tmp_next;
	}
}
