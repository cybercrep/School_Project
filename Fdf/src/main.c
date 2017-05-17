/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 10:56:05 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/08 00:00:51 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		make_first_img(t_all *all)
{
	t_point		zoom;
	t_point		decal;

	zoom.x = 10;
	zoom.y = 2;
	decal.x = 0;
	decal.y = 0;
	trace_map(decal, zoom, all);
}

int				main(int argc, const char *argv[])
{
	t_all		all;

	if (argc != 2)
		exit(-1);
	if ((all.map = parseur(argv[1])) == NULL)
		exit(-1);
	if (init_mlx(&all) == -1)
	{
		ft_putstr_fd(2, "Initiallisation mlx error\n");
		exit(-1);
	}
	make_first_img(&all);
	mlx_hook(all.pt_mlx.win, 2, (1L << 1), &fdf_key_hook, &all);
	mlx_loop(all.pt_mlx.mlx);
	exit(0);
}
