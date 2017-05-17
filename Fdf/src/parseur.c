/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 04:12:44 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/07 23:32:22 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			is_carrer(t_int2d *out)
{
	size_t		i;
	size_t		max;

	i = 0;
	max = *out->nb_by_line;
	while (++i < out->nb_line)
	{
		if (out->nb_by_line[i] != max)
			return (0);
	}
	return (1);
}

static t_int2d		*make_tab(const int fd, size_t i)
{
	int			ret;
	t_int2d		*out;
	char		*line;

	line = NULL;
	if ((ret = get_next_line(fd, &line)) == -1)
		return (NULL);
	if (ret && !*line)
		return (NULL);
	if (ret == 0)
	{
		out = ft_new_int2d(i);
		return (out);
	}
	else
	{
		if ((out = make_tab(fd, i + 1)) == NULL)
			return (NULL);
	}
	if ((out->tab[i] = ft_gentabint(line, &out->nb_by_line[i], 0)) == NULL)
		return (NULL);
	ft_strdel(&line);
	return (out);
}

t_int2d				*parseur(const char *path)
{
	int			fd;
	t_int2d		*out;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		perror("open");
		return (NULL);
	}
	if ((out = make_tab(fd, 0)) == NULL)
	{
		ft_putstr_fd(2, "Map Error\n");
		return (NULL);
	}
	if (close(fd) == -1)
		perror("close");
	if (!is_carrer(out))
	{
		ft_putstr_fd(2, "Map Error\n");
		ft_free_int2d(&out);
	}
	return (out);
}
