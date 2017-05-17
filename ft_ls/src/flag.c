/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 05:27:56 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/25 01:02:01 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		flag(const char *str)
{
	if (*str != '-')
		return (-1);
	str++;
	if (*str == '-')
		return (0);
	while (*str)
	{
		if (*str == 'l')
			g_flag = g_flag | ARG_L;
		else if (*str == 'a')
			g_flag = g_flag | ARG_A;
		else if (*str == 'r')
			g_flag = g_flag | ARG_R;
		else if (*str == 'R')
			g_flag = g_flag | ARG_RR;
		else if (*str == 't')
			g_flag = g_flag | ARG_T;
		else
			print_usage(*str);
		str++;
	}
	return (1);
}
