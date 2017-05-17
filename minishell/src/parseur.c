/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 05:03:16 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/28 14:40:04 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void		parseur(char *line)
{
	char		**tmp;

	tmp = ft_makearg(line, 0);
	ft_strdel(&line);
	if (tmp == NULL)
		return ;
	if (!ft_strcmp(tmp[0], "exit"))
		ft_exit(tmp);
	else if (!ft_strcmp(tmp[0], "putenv"))
		ft_putendl_free(ft_getenv_valu(tmp[1], 0));
	else if (!ft_strcmp(tmp[0], "setenv"))
		ft_env(tmp[1], NULL, ENV_SET, 0);
	else if (!ft_strcmp(tmp[0], "env"))
		ft_runenv(&tmp[1]);
	else if (!ft_strcmp(tmp[0], "unsetenv"))
		ft_env(tmp[1], NULL, ENV_UNSET, 0);
	else if (!ft_strcmp(tmp[0], "cd"))
		ft_cd(tmp[1]);
	else if (!ft_strcmp(tmp[0], "echo"))
		ft_echo((const char **)&tmp[1]);
	else
		cmd(tmp, 0);
	ft_strdel_2d(&tmp);
}
