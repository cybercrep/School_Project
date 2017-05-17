/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 02:09:52 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/28 14:42:12 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, const char *argv[], char *env[])
{
	(void)argv;
	if (argc != 1)
		return (-1);
	if (ft_initenv(env) == -1)
		exit(EXIT_FAILURE);
	loop();
	ft_putchar('\n');
	ft_exit(NULL);
}
