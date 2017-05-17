/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 03:14:51 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/06 04:10:32 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vswap(void *pt_1, void *pt_2)
{
	void	*tmp;

	tmp = pt_1;
	pt_1 = pt_2;
	pt_2 = tmp;
}
