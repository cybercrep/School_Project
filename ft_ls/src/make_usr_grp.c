/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_usr_grp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 05:35:44 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/25 19:47:16 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			make_usr_grp(t_2lst_info *mallion)
{
	if ((mallion->info_pass = getpwuid(mallion->st_info.st_uid)) == NULL)
		return (-1);
	if ((mallion->info_grp = getgrgid(mallion->st_info.st_gid)) == NULL)
		return (-1);
	mallion->print_l[L_USR] = ft_strdup(mallion->info_pass->pw_name);
	mallion->size_l[L_USR] = ft_strlen(mallion->print_l[L_USR]);
	mallion->print_l[L_GRP] = ft_strdup(mallion->info_grp->gr_name);
	mallion->size_l[L_GRP] += ft_strlen(mallion->print_l[L_GRP]);
	return (1);
}
