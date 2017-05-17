/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_indir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 06:00:11 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/27 20:35:24 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_is_indir(const char *name, const char *path)
{
	DIR					*fd_dir;
	struct dirent		*file;

	if ((fd_dir = opendir(path)) == NULL)
	{
		return (-1);
	}
	while ((file = readdir(fd_dir)) != NULL)
	{
		if (ft_strcmp(file->d_name, name) == 0)
		{
			if (closedir(fd_dir) == -1)
				exit(EXIT_FAILURE);
			return (1);
		}
	}
	if (closedir(fd_dir) == -1)
		exit(EXIT_FAILURE);
	return (0);
}
