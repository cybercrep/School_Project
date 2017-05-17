/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 20:45:07 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/21 16:08:51 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			ft_initenv(char **env)
{
	while (*env)
	{
		if (ft_env(*env, NULL, ENV_SET, 0) == -1)
		{
			ft_putstr_fd(2, "fail in initalisation of env\n");
			return (-1);
		}
		env++;
	}
	return (1);
}
