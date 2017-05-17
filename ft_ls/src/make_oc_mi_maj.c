/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_oc_mi_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:06:35 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/21 04:16:11 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		make_size_oc(t_2lst_info *lst)
{
	char	*tmp_ma;
	char	*tmp_mi;

	if (S_ISREG(lst->st_info.st_mode) | S_ISDIR(lst->st_info.st_mode)
			| S_ISLNK(lst->st_info.st_mode))
	{
		if ((lst->print_l[L_OC] = itoa_off_t(lst->st_info.st_size)) == NULL)
			return (-1);
	}
	else
	{
		tmp_ma = ft_itoa(MAJOR(lst->st_info.st_rdev));
		tmp_mi = ft_itoa(MINOR(lst->st_info.st_rdev));
		lst->print_l[L_OC] = ft_strintercal(tmp_ma, ',', tmp_mi);
	}
	return (1);
}
