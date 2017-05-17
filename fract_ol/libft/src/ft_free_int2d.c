/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 21:24:52 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/07 21:32:07 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_int2d(t_int2d **as)
{
	size_t		i;
	t_int2d		*tmp;

	i = 0;
	tmp = *as;
	if (tmp->nb_by_line != NULL)
		free(tmp->nb_by_line);
	while (i < tmp->nb_line)
	{
		free(tmp->tab[i]);
		i++;
	}
	free(tmp->tab);
	free(tmp);
	*as = NULL;
}
