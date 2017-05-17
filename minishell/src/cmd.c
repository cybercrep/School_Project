/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 00:25:40 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/28 16:31:44 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_access(const char *path)
{
	if (access(path, F_OK) == -1)
	{
		ft_error(path, "No such file or directory: ");
		return (-1);
	}
	if (access(path, X_OK) == -1)
	{
		ft_error(path, "permission denied: ");
		return (0);
	}
	return (1);
}

void		cmd(char **str, int n_env)
{
	char			*path;

	path = NULL;
	if (**str == '.' || **str == '/')
		path = ft_strdup(*str);
	else
	{
		if ((path = ft_get_path(*str)) == NULL)
		{
			ft_error(*str, "command not found: ");
			return ;
		}
	}
	if (check_access(path) == 1)
		ft_new_process(path, str, ft_getenv_tab(n_env));
	ft_strdel(&path);
}
