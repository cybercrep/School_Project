/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:08:29 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/11/10 23:30:27 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, const char *argv[])
{
	t_all	all;

	if (argc != 2)
		put_usage();
	if (init_all(&all) == -1)
	{
		ft_putstr_fd(2, "fail init_mlx");
		exit(EXIT_FAILURE);
	}
	parseur(argv, &all);
	expose_hook(&all);
	mlx_put_image_to_window(all.pt_mlx.mlx,
			all.pt_mlx.win, all.image.img, 0, 0);
	mlx_hook(all.pt_mlx.win, 2, (1L << 1), &key_hook, &all);
	mlx_hook(all.pt_mlx.win, 6, (1L << 6), &mouse_pos, &all);
	mlx_mouse_hook(all.pt_mlx.win, mouse_hook, &all);
	mlx_loop(all.pt_mlx.mlx);
	return (0);
}
