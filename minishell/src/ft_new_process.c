/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_forck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 03:23:50 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/28 15:29:51 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_new_process(char *path, char **av, char **env)
{
	int			ret;
	pid_t		pid;

	if ((pid = fork()) == -1)
	{
		ft_putstr_fd(2, "fork fail\n");
		return (-1);
	}
	if (pid > 0)
		wait(&ret);
	if (pid == 0)
	{
		if (execve(path, av, env) == -1)
		{
			ft_putstr_fd(2, "execve fail\n");
			exit(EXIT_FAILURE);
		}
	}
	ft_strdel_2d(&env);
	return (ret);
}
