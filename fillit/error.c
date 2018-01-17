/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 22:54:09 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 22:54:09 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	error(char *error_msg)
{
	if (SHOW_ERROR)
	{
		ft_putstr_fd(error_msg, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		ft_putstr_fd("error\n", 1);
	exit(EXIT_FAILURE);
}
