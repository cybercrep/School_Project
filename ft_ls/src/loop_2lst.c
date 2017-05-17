/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lst_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 01:50:50 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/05/25 01:54:17 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		loop_2lst(t_2lst_info *lst)
{
	t_2lst_info		*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lst;
	lst->last = tmp;
}
