/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_2lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 22:40:03 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/29 04:53:58 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		reverse_2lst(t_2lst_info **begin_lst)
{
	t_2lst_info		*tmp;
	t_2lst_info		*tmp_next;

	if ((tmp = *begin_lst) == NULL)
		return ;
	while (tmp->next)
	{
		tmp_next = tmp->next;
		tmp->next = tmp->last;
		tmp->last = tmp_next;
		tmp = tmp_next;
	}
	tmp->next = tmp->last;
	tmp->last = NULL;
	*begin_lst = tmp;
}
