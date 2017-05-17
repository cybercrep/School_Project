/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 00:50:51 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/21 16:45:07 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char		*ft_getenv_valu(const char *key, int n_env)
{
	char		*out;
	t_env		buf;

	if (ft_env(key, &buf, ENV_GET, n_env) == -1)
		return (NULL);
	if ((out = ft_strdup(buf.valu)) == NULL)
		return (NULL);
	return (out);
}

char		*ft_getenv_all(const char *key, int n_env)
{
	char		*out;
	t_env		buf;

	if (ft_env(key, &buf, ENV_GET, n_env) == -1)
		return (NULL);
	if ((out = ft_strdup(buf.all)) == NULL)
		return (NULL);
	return (out);
}

char		**ft_getenv_tab(int n_env)
{
	int			ret;
	char		**out;
	char		**pt_out;
	t_env		buf;

	if ((out = malloc(sizeof(char *)
					* (ft_env(NULL, NULL, ENV_SIZE, n_env) + 1))) == NULL)
		return (NULL);
	pt_out = out;
	while ((ret = ft_env(NULL, &buf, ENV_READ, n_env)) > 0)
	{
		*pt_out = ft_strdup(buf.all);
		pt_out++;
	}
	if (ret == -1)
		return (NULL);
	*pt_out = NULL;
	return (out);
}
