/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 22:54:11 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 21:54:51 by legrivel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int x)
{
	double	a;
	double	b;

	if (x > 0)
	{
		a = 1;
		b = x;
		while (ft_abs(a - b))
		{
			a = (a + b) / 2;
			b = x / a;
		}
		return ((int)a);
	}
	return (0);
}

int		main(int argc, const char *argv[])
{
	int				fd;
	int				nbr_pieces;
	unsigned int	pieces[MAX_PIECES + 1];
	t_square		*map;
	t_point			*pos_tab;

	if (argc != 2)
		error("need just 1 arg. its name of file to resolve");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error("fail open");
	if ((nbr_pieces = read_input(fd, pieces)) <= 0)
		error("fail read input");
	map = init_map(pieces, nbr_pieces);
	pos_tab = init_pos_tab(nbr_pieces);
	map->size_mini = ft_sqrt(2 * nbr_pieces) + 1;
	while (!solve(map, pos_tab, 0, 0))
	{
		reset_pos_tab(pos_tab, 0, nbr_pieces);
		map->size_mini++;
	}
	putmap(filltab(inittab(map->size_mini), map, pos_tab));
	free(pos_tab);
	free(map);
	return (0);
}
