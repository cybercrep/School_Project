/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 05:46:55 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/12 05:48:22 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			ft_envlen(t_env *begin)
{
	int			i;
	t_env		*tmp;

	i = 0;
	tmp = begin;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
