/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 20:58:40 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/29 05:29:43 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls(t_2lst_info *begin_lst)
{
	t_2lst_info		*tmp;

	tmp = begin_lst;
	while (tmp && ((g_flag & ARG_L && !S_ISDIR(tmp->st_info.st_mode))
				|| (!S_ISDIR(tmp->st_info.st_mode)
					&& !S_ISLNK(tmp->st_info.st_mode))))
	{
		print(tmp, 0);
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->last)
			ft_putstr("\n");
		if (tmp->next != NULL || tmp != begin_lst)
			putpath(tmp->print_l[L_NAME]);
		lest_go(ft_strdup(tmp->print_l[L_NAME]));
		tmp = tmp->next;
	}
	del_2lst_info(&begin_lst);
}

int		main(int argc, const char *argv[])
{
	t_2lst_info		*begin_lst;

	g_flag = 0;
	if (argc == 1)
		lest_go(ft_strdup("."));
	else
	{
		if ((begin_lst = parseur(argc - 1, &argv[1])) == NULL)
			lest_go(ft_strdup("."));
		else
			ls(begin_lst);
	}
	exit(0);
}
