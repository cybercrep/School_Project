/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:31:25 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/11/11 03:34:23 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		parseur(const char **argv, t_all *all)
{
	if (ft_strcmp(argv[1], "-m") == 0)
		all->focus = 1;
	else if (ft_strcmp(argv[1], "-j") == 0)
		all->focus = 2;
	else if (ft_strcmp(argv[1], "-b") == 0)
		all->focus = 3;
	else
		put_usage();
}
