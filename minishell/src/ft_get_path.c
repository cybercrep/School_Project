/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 05:02:33 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/27 21:03:24 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_path(const char *name)
{
	int			i;
	char		*tmp;
	char		*out;
	char		**all_path;

	i = 0;
	out = NULL;
	if ((tmp = ft_getenv_valu("PATH", 0)) == NULL)
		return (NULL);
	all_path = ft_strsplit_free(&tmp, ':');
	ft_strdel(&tmp);
	while (all_path[i])
	{
		if (ft_is_indir(name, all_path[i]) == 1)
			break ;
		i++;
	}
	if (all_path[i] != NULL)
		out = ft_strintercal(all_path[i], '/', name);
	ft_strdel_2d(&all_path);
	return (out == NULL) ? NULL : out;
}
