/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 18:46:24 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/29 04:53:42 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	make_max_size(t_2lst_info *mallion, size_t *max_size)
{
	int		i;

	i = 0;
	while (i != MAX_ELEM)
	{
		if (max_size[i] < mallion->size_l[i])
			max_size[i] = mallion->size_l[i];
		i++;
	}
}

static int	str_list(t_2lst_info *begin_lst, size_t *max_size)
{
	t_2lst_info		*lst;

	lst = begin_lst;
	while (lst != NULL)
	{
		max_size[L_NAME] = lst->size_l[L_NAME];
		lst->print_l[L_PRINT] = ft_strjoin_one_size(
				(const char **)&lst->print_l[1], &max_size[1], MAX_ELEM - 1);
		if (lst->print_l[L_PRINT] == NULL)
			return (-1);
		lst = lst->next;
	}
	return (1);
}

int			make_str(t_2lst_info *lst)
{
	int		ret;

	ret = 0;
	ret += make_right(lst);
	ret += make_usr_grp(lst);
	ret += make_size_oc(lst);
	ret += make_time(lst);
	ret += make_link(lst);
	if (S_ISLNK(lst->st_info.st_mode))
		if (make_name_link(lst) == -1)
			return (-1);
	if (ret != 5)
		return (-1);
	return (1);
}

char		*make_str_list(t_2lst_info *begin_lst)
{
	char			*out;
	size_t			tt;
	size_t			max_size[MAX_ELEM + 1];
	t_2lst_info		*lst;

	tt = 0;
	lst = begin_lst;
	ft_inittab_size_t(max_size, MAX_ELEM);
	while (lst != NULL)
	{
		if (make_str(lst) == -1)
			return (NULL);
		make_size_l(lst);
		make_max_size(lst, max_size);
		tt += lst->st_info.st_blocks;
		lst = lst->next;
	}
	if (str_list(begin_lst, max_size) == -1)
		return (NULL);
	return (out = ft_itoa_size_t(tt)) ? out : NULL;
}
