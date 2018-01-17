/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 22:54:11 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 19:27:17 by legrivel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_square		*init_map(unsigned int *pieces, int nbr_pieces)
{
	t_square	*tmp;

	if ((tmp = (t_square*)malloc(sizeof(t_square))) == NULL)
		error("fail malloc init_map");
	tmp->nbr_pieces = nbr_pieces;
	tmp->pieces = pieces;
	return (tmp);
}

t_point			*init_pos_tab(int nbr_pieces)
{
	t_point		*tmp;
	int			i;

	i = -1;
	if ((tmp = (t_point*)malloc(sizeof(t_point) * nbr_pieces)) == NULL)
		error("fail malloc init_pos_tab");
	while (++i < nbr_pieces)
	{
		(&tmp[i])->x = -21;
		(&tmp[i])->y = -21;
	}
	return (tmp);
}

char			**inittab(int sq_size)
{
	char	**tab;
	int		i;

	if (!(tab = (char**)malloc((sq_size + 1) * sizeof(char **))))
		error("Null malloc");
	tab[sq_size] = NULL;
	i = -1;
	while (++i < sq_size)
	{
		if (!(tab[i] = ft_strnew((sq_size + 1) * sizeof(char *))))
		{
			while (i >= 0)
				free(tab[i--]);
			free(tab);
			error("Null malloc");
		}
		ft_memset(tab[i], '.', sq_size);
	}
	return (tab);
}
