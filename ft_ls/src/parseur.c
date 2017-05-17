/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 20:54:48 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/30 10:57:03 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		makelst(int argc, const char *argv[], t_2lst_info **lst)
{
	int				i;
	t_2lst_info		*tmp;

	i = 0;
	while (i != argc)
	{
		if ((tmp = new_2lst_info()) == NULL)
			fail("malloc");
		tmp->print_l[L_NAME] = ft_strdup(argv[i++]);
		if (lstat(tmp->print_l[L_NAME], &tmp->st_info) == -1)
		{
			fail(tmp->print_l[L_NAME]);
			del_2lst_info(&tmp);
			continue ;
		}
		if (*lst != NULL)
			inser(lst, tmp, &dir_cmp);
		else
			*lst = tmp;
	}
	return (i >= 1) ? 1 : 0;
}

t_2lst_info		*parseur(int argc, const char *argv[])
{
	int				i;
	int				ret;
	t_2lst_info		*begin_lst;

	i = 0;
	ret = 0;
	begin_lst = NULL;
	while (i < argc && (ret = flag(argv[i])) == 1)
		i++;
	if (!ret)
		i++;
	if (i == argc)
		return (NULL);
	if (makelst(argc - i, &argv[i], &begin_lst) == 1 && begin_lst == NULL)
		exit(1);
	return (begin_lst);
}
