/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:11:23 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/21 04:14:42 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		make_link(t_2lst_info *lst)
{
	if ((lst->print_l[L_LINK] = itoa_nlink_t(lst->st_info.st_nlink)) == NULL)
		return (-1);
	return (1);
}
