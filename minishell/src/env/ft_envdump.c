/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dumpenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:00:26 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/21 16:10:25 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			ft_envdump(int dst, int src)
{
	int			ret;
	t_env		buf;

	while ((ret = ft_env(NULL, &buf, ENV_READ, src)) == 1)
	{
		if (ft_env(buf.all, NULL, ENV_SET, dst) == -1)
			return (-1);
	}
	if (ret == -1)
		return (-1);
	return (1);
}
