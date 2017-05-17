/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_int2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 11:34:19 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/06 03:41:06 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int2d		*ft_new_int2d(size_t nb_line)
{
	size_t		i;
	t_int2d		*tmp;

	i = 0;
	if ((tmp = malloc(sizeof(t_int2d))) == NULL)
		return (NULL);
	if ((tmp->nb_by_line = malloc(sizeof(size_t) * nb_line)) == NULL)
	{
		free(tmp);
		return (NULL);
	}
	if ((tmp->tab = malloc(sizeof(int *) * nb_line)) == NULL)
	{
		free(tmp->nb_by_line);
		free(tmp);
		return (NULL);
	}
	tmp->nb_line = nb_line;
	while (i < nb_line)
	{
		tmp->nb_by_line[i] = 0;
		tmp->tab[i] = NULL;
		i++;
	}
	return (tmp);
}
