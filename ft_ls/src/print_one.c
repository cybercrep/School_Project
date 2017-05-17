/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 00:37:24 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/24 02:03:37 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_one(t_2lst_info *lst)
{
	t_2lst_info		*tmp_next;

	tmp_next = lst->next;
	lst->next = NULL;
	lst->path = lst->print_l[L_NAME];
	if (make_str_list(lst) == NULL)
		fail("make print list");
	lst->path = NULL;
	lst->next = tmp_next;
	ft_putendl(lst->print_l[L_PRINT]);
}
