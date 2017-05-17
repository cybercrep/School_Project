/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 04:53:00 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/28 16:36:23 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void		loop(void)
{
	int		ret;
	char	*pwd;
	char	*line;

	pwd = NULL;
	line = NULL;
	while (42)
	{
		if ((pwd = ft_getenv_valu("PWD", 0)) != NULL)
		{
			ft_putstr("\n");
			ft_putcolor(pwd, C_GREEN);
		}
		ft_putstr("\n$>");
		ft_strdel(&pwd);
		if ((ret = get_next_line(1, &line)) == 0)
			break ;
		if (*line == '\0' || ret == -1)
		{
			ret == -1 ? ft_error("try again", "Read fail: ") : 0;
			ft_strdel(&line);
			continue ;
		}
		parseur(line);
	}
}
