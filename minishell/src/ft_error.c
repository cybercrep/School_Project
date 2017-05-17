/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 20:42:51 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/25 20:49:41 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		ft_error(const char *path, const char *str)
{
	ft_putstr_fd(2, "minishell: ");
	ft_putstr_fd(2, str);
	ft_putstr_fd(2, path);
	ft_putchar_fd(2, '\n');
}
