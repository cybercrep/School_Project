/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 04:50:09 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/21 16:03:30 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_chdir(char *path)
{
	if (chdir(path) == -1)
		ft_putstr_fd(2, "no such file or directory\n");
	ft_strdel(&path);
}

void			ft_cd(const char *path)
{
	static char		*last_path = NULL;
	static size_t	buf_size = 256;
	char			*tmp;
	char			buf[buf_size];

	getcwd(buf, buf_size);
	if (path == NULL)
		ft_chdir(ft_getenv_valu("HOME", 0));
	else if (ft_strcmp(path, "-") == 0)
	{
		if (last_path == NULL)
			ft_chdir(ft_getenv_valu("HOME", 0));
		else
			ft_chdir(ft_strdup(last_path));
	}
	else
		ft_chdir(ft_strdup(path));
	ft_strdel(&last_path);
	last_path = ft_strdup(buf);
	getcwd(buf, buf_size);
	tmp = ft_strjoin("PWD=", buf);
	ft_env(tmp, NULL, ENV_SET, 0);
	ft_strdel(&tmp);
}
