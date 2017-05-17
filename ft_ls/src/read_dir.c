/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 23:17:12 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/29 02:05:08 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_2lst_info		*take_info(DIR *fd_dir, const char *path)
{
	t_2lst_info		*tmp;

	if ((tmp = new_2lst_info()) == NULL)
		return (NULL);
	if ((tmp->info_dir = readdir(fd_dir)) == NULL)
	{
		fail("???takeinfo");
		del_2lst_info(&tmp);
		return (NULL);
	}
	tmp->print_l[L_NAME] = ft_strdup(tmp->info_dir->d_name);
	tmp->size_l[L_NAME] = ft_strlen(tmp->print_l[L_NAME]);
	if ((tmp->path = ft_strintercal(path, '/', tmp->print_l[L_NAME])) == NULL)
		fail("make_path");
	if (lstat(tmp->path, &tmp->st_info) == -1)
		fail("lstat");
	return (tmp);
}

t_2lst_info		*read_dir(DIR *fd_dir, const char *path)
{
	t_2lst_info		*out;
	t_2lst_info		*tmp;

	out = NULL;
	while ((tmp = take_info(fd_dir, path)) != NULL)
	{
		if (!(g_flag & ARG_A) && tmp->print_l[L_NAME][0] == '.')
		{
			del_2lst_info(&tmp);
			continue;
		}
		else if (out == NULL)
			out = tmp;
		else
		{
			if (g_flag & ARG_T)
				inser(&out, tmp, &time_cmp);
			else
				inser(&out, tmp, &alpha_cmp);
		}
	}
	if (g_flag & ARG_R)
		reverse_2lst(&out);
	return (out);
}
