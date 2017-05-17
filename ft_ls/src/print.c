/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 05:14:56 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/25 19:11:40 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print(t_2lst_info *lst, int bol)
{
	if (bol)
	{
		if (g_flag & ARG_L)
			print_list(lst);
		else
			print_name(lst);
	}
	else
	{
		if (g_flag & ARG_L)
			print_one(lst);
		else
			ft_putendl(lst->print_l[L_NAME]);
	}
}
