/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 03:52:18 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/14 10:21:19 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_echo(const char **argv)
{
	char		*tmp;

	if (*argv == NULL)
		return ;
	if (!ft_strcmp(argv[0], "-n"))
	{
		if (argv[1] == NULL)
			return ;
		if ((tmp = ft_strjoinspace_2d(&argv[1])) == NULL)
			return ;
		ft_putstr(tmp);
	}
	else
	{
		if ((tmp = ft_strjoinspace_2d(argv)) == NULL)
			return ;
		ft_putendl(tmp);
	}
	ft_strdel(&tmp);
}
