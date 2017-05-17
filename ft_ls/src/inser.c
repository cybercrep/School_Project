/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 02:27:43 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/25 16:40:39 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			dir_cmp(t_2lst_info *ref, t_2lst_info *cmp)
{
	int		i_ref;
	int		i_cmp;

	i_ref = (!S_ISDIR(ref->st_info.st_mode)) ? 0 : 1;
	i_cmp = (!S_ISDIR(cmp->st_info.st_mode)) ? 0 : 1;
	if (!(g_flag & ARG_L))
	{
		i_ref += (!S_ISLNK(ref->st_info.st_mode)) ? 0 : 1;
		i_cmp += (!S_ISLNK(cmp->st_info.st_mode)) ? 0 : 1;
	}
	if (!i_ref && !i_cmp)
		return (g_flag & ARG_T) ? time_cmp(ref, cmp) : alpha_cmp(ref, cmp);
	else if (i_ref && i_cmp)
		return (g_flag & ARG_T) ? time_cmp(ref, cmp) : alpha_cmp(ref, cmp);
	else
	{
		if (i_cmp)
			return (-1);
		else
			return (1);
	}
}

int			alpha_cmp(t_2lst_info *ref, t_2lst_info *cmp)
{
	return (ft_strcmp(ref->print_l[L_NAME], cmp->print_l[L_NAME]));
}

int			time_cmp(t_2lst_info *ref, t_2lst_info *cmp)
{
	if (ref->st_info.st_mtimespec.tv_sec == cmp->st_info.st_mtimespec.tv_sec)
	{
		if (ref->st_info.st_mtimespec.tv_nsec
			== cmp->st_info.st_mtimespec.tv_nsec)
			return (alpha_cmp(ref, cmp));
		if (ref->st_info.st_mtimespec.tv_nsec
			< cmp->st_info.st_mtimespec.tv_nsec)
			return (1);
		else
			return (-1);
	}
	if (ref->st_info.st_mtimespec.tv_sec < cmp->st_info.st_mtimespec.tv_sec)
		return (1);
	else
		return (-1);
}

void		inser(t_2lst_info **begin_lst, t_2lst_info *a_placer, int (*foo)())
{
	int				ret;
	t_2lst_info		*tmp;

	tmp = *begin_lst;
	while ((ret = foo(a_placer, tmp)) > 0 && tmp->next)
		tmp = tmp->next;
	if (tmp == *begin_lst && ret <= 0)
	{
		*begin_lst = a_placer;
		a_placer->next = tmp;
		a_placer->last = NULL;
		tmp->last = a_placer;
	}
	else if (tmp->next == NULL && ret >= 0)
	{
		a_placer->last = tmp;
		tmp->next = a_placer;
	}
	else
	{
		a_placer->next = tmp;
		a_placer->last = tmp->last;
		tmp->last->next = a_placer;
		tmp->last = a_placer;
	}
}
