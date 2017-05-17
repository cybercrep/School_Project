/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 05:52:08 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/27 18:05:01 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exit(char **argv)
{
	if (argv != NULL)
		ft_strdel_2d(&argv);
	ft_env(NULL, NULL, ENV_CLEAR, 0);
	exit(EXIT_SUCCESS);
}
