/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 18:18:35 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/21 04:22:13 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_name(t_2lst_info *lst)
{
	while (lst != NULL)
	{
		ft_putendl(lst->print_l[L_NAME]);
		lst = lst->next;
	}
	ft_putstr("\n");
}
