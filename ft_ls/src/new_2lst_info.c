/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_2lst_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:28:18 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/29 00:09:42 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_2lst_info		*new_2lst_info(void)
{
	t_2lst_info		*tmp;

	if ((tmp = (t_2lst_info *)malloc(sizeof(t_2lst_info))) == NULL)
		return (NULL);
	tmp->path = NULL;
	ft_initstr_2d(tmp->print_l, MAX_ELEM + 1);
	ft_inittab_size_t(tmp->size_l, MAX_ELEM);
	tmp->info_dir = NULL;
	tmp->info_pass = NULL;
	tmp->info_grp = NULL;
	tmp->next = NULL;
	tmp->last = NULL;
	return (tmp);
}
