/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 21:34:33 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/07 21:52:46 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_all(t_all *all)
{
	mlx_destroy_image(all->pt_mlx.mlx, all->image.img);
	mlx_destroy_window(all->pt_mlx.mlx, all->pt_mlx.win);
	ft_free_int2d(&all->map);
}
