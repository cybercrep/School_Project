/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 15:59:44 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/27 20:23:03 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_runenv(char **argv)
{
	int			i;
	int			bol;

	i = 0;
	bol = 0;
	if (*argv == NULL)
	{
		ft_putenv(0);
		return ;
	}
	ft_envdump(1, 0);
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-i"))
			ft_env(NULL, NULL, ENV_CLEAR, 1);
		else if (ft_strchr(argv[i], '=') != NULL)
			ft_env(argv[i], NULL, ENV_SET, 1);
		else
		{
			cmd(&argv[i], 1);
			break ;
		}
		i++;
	}
}
