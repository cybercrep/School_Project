/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_size_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 07:25:57 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/02 07:30:00 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		make_size_l(t_2lst_info *mallion)
{
	size_t		i;

	i = 1;
	while (i != MAX_ELEM)
	{
		if (mallion->print_l[i] != NULL)
			mallion->size_l[i] = ft_strlen(mallion->print_l[i]);
		else
			mallion->size_l[i] = 0;
		i++;
	}
}
