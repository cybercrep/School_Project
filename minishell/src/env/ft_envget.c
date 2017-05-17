/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 00:50:51 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/21 16:47:27 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			ft_envget(const char *str, t_env *buf, t_env *begin)
{
	t_env			*tmp;

	tmp = begin;
	while (tmp && ft_strcmp(tmp->key, str))
		tmp = tmp->next;
	if (tmp == NULL)
		return (-1);
	*buf = *tmp;
	return (1);
}

int			ft_envget_all(t_env *begin, t_env *buf)
{
	static t_env	*curs = NULL;

	if (curs == NULL)
	{
		curs = begin;
		if (begin == NULL)
			return (0);
	}
	else if ((curs = curs->next) == NULL)
		return (0);
	*buf = *curs;
	return (1);
}
