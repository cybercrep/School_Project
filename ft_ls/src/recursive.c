/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 18:57:11 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/28 03:08:45 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		recursive(char *path, t_2lst_info *begin_lst)
{
	char			*tmp_path;
	t_2lst_info		*tmp;

	tmp = begin_lst;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->print_l[L_NAME], ".") != 0
				&& ft_strcmp(tmp->print_l[L_NAME], "..") != 0)
		{
			if (S_ISDIR(tmp->st_info.st_mode))
			{
				if ((tmp_path = ft_strintercal(
								path, '/', tmp->print_l[L_NAME])) == NULL)
					fail("make_path");
				ft_putstr("\n");
				putpath(tmp_path);
				lest_go(tmp_path);
				tmp_path = NULL;
			}
		}
		tmp = tmp->next;
	}
	del_2lst_info(&begin_lst);
}
