/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 18:28:45 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/27 18:32:08 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_free_cmd(char *path, char **av, char **env)
{
	ft_strdel(&path);
	ft_strdel_2d(&av);
	ft_strdel_2d(&env);
}
