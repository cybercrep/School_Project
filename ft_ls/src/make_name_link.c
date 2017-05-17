/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_name_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 01:25:47 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/21 06:20:12 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		make_name_link(t_2lst_info *mallion)
{
	size_t		ret;
	char		*tmp;
	char		*pt_tmp;
	char		buf[BUFF_LNK + 1];

	if ((ret = readlink(mallion->path, buf, BUFF_LNK)) <= 0)
		return (-1);
	buf[ret] = '\0';
	if ((tmp = ft_strnew(ret + 4 + ft_strlen(mallion->print_l[L_NAME])))
			== NULL)
		return (-1);
	pt_tmp = tmp;
	pt_tmp += ft_strcpy(pt_tmp, mallion->print_l[L_NAME]);
	free(mallion->print_l[L_NAME]);
	pt_tmp += ft_strcpy(pt_tmp, " -> ");
	pt_tmp += ft_strcpy(pt_tmp, buf);
	mallion->print_l[L_NAME] = tmp;
	return (1);
}
