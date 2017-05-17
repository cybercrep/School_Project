/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 19:10:17 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/27 19:14:02 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_putendl_free(char *str)
{
	write(1, str, ft_strlen(str));
	ft_strdel(&str);
	ft_putchar('\n');
}
