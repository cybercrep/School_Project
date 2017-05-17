/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 03:21:53 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/21 16:06:47 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		ft_putenv(int n_env)
{
	char	**env;

	if ((env = ft_getenv_tab(n_env)) == NULL)
	{
		ft_putstr_fd(2, "error print env\n");
		return ;
	}
	ft_putendl_2d((const char **)env);
	ft_strdel_2d(&env);
}
