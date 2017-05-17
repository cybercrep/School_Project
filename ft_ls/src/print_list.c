/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 06:13:28 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/26 05:05:01 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_list(t_2lst_info *begin_lst)
{
	char			*tt;
	t_2lst_info		*tmp;

	tmp = begin_lst;
	if ((tt = make_str_list(begin_lst)) == NULL)
		fail("make print list");
	ft_putstr("total ");
	ft_putendl(tt);
	free(tt);
	tt = NULL;
	while (tmp)
	{
		ft_putendl(tmp->print_l[L_PRINT]);
		tmp = tmp->next;
	}
}
