/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 02:32:39 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/10 19:23:18 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env			*ft_new_env(const char *all)
{
	t_env			*tmp_env;
	char			*tmp;

	if ((tmp_env = malloc(sizeof(t_env))) == NULL)
		return (NULL);
	if ((tmp = ft_strchr(all, '=')) == NULL)
		return (NULL);
	if ((tmp_env->key = ft_strndup(all, (tmp - all))) == NULL)
		return (NULL);
	if ((tmp_env->valu = ft_strdup(tmp + 1)) == NULL)
		return (NULL);
	if ((tmp_env->all = ft_strdup(all)) == NULL)
		return (NULL);
	tmp_env->next = NULL;
	tmp_env->last = NULL;
	return (tmp_env);
}
