/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 02:32:39 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/27 21:23:53 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int				ft_envreset(t_env *env, t_env *begin)
{
	t_env			*tmp;

	tmp = begin;
	while (tmp && ft_strcmp(tmp->key, env->key))
		tmp = tmp->next;
	if (tmp == NULL)
		return (-1);
	free(tmp->valu);
	free(tmp->all);
	tmp->valu = env->valu;
	tmp->all = env->all;
	free(env->key);
	free(env);
	return (1);
}

int				ft_setenv(const char *all, t_env **begin, t_env **last)
{
	t_env			*tmp_env;

	if ((tmp_env = ft_new_env(all)) == NULL)
		return (-1);
	if (ft_envreset(tmp_env, *begin) == 1)
		return (1);
	tmp_env->last = *last;
	if (*last != NULL)
	{
		(*last)->next = tmp_env;
		*last = tmp_env;
	}
	else
	{
		*begin = tmp_env;
		*last = tmp_env;
	}
	return (1);
}

int				ft_envunset(const char *key, t_env **begin, t_env **last)
{
	t_env			*tmp;

	tmp = *begin;
	while (tmp && ft_strcmp(tmp->key, key))
		tmp = tmp->next;
	if (tmp == NULL)
		return (-1);
	free(tmp->key);
	free(tmp->valu);
	free(tmp->all);
	if (tmp->last != NULL)
		tmp->last->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->last = tmp->last;
	if (tmp == *begin)
		*begin = tmp->next;
	if (tmp == *last)
		*last = tmp->last;
	free(tmp);
	return (1);
}

int				ft_envclear(t_env **begin, t_env **last)
{
	t_env			*tmp;
	t_env			*tmp_next;

	tmp = *begin;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp->key);
		free(tmp->valu);
		free(tmp->all);
		free(tmp);
		tmp = tmp_next;
	}
	*begin = NULL;
	*last = NULL;
	return (1);
}

int				ft_env(const char *str, t_env *buf, int key, int i)
{
	static t_env	*begin[2] = {NULL, NULL};
	static t_env	*last[2] = {NULL, NULL};

	if (i > NB_ENV)
		return (-1);
	if (key & NEED_STR)
		if (str == NULL)
			return (-1);
	if (key & NEED_BUF)
		if (buf == NULL)
			return (-1);
	if (key == ENV_SET)
		return (ft_setenv(str, &begin[i], &last[i]));
	if (key == ENV_UNSET)
		return (ft_envunset(str, &begin[i], &last[i]));
	if (key == ENV_SIZE)
		return (ft_envlen(begin[i]));
	if (key == ENV_GET)
		return (ft_envget(str, buf, begin[i]));
	if (key == ENV_READ)
		return (ft_envget_all(begin[i], buf));
	if (key == ENV_CLEAR)
		return (ft_envclear(&begin[i], &last[i]));
	return (-1);
}
