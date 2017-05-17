/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 02:06:10 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/28 16:31:15 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
********************************************************************************
**							INCLUDES                                          **
********************************************************************************
*/

# include "libft.h"
# include "env.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>

/*
********************************************************************************
**							INCLUDES                                          **
********************************************************************************
*/

void			loop(void);
void			parseur(char *line);

/*
**	in ft_makearg.c
*/
char			**ft_makearg(char *line, int i);

int				ft_new_process(char *path, char **av, char **env);

char			*ft_get_path(const char *name);
int				ft_is_indir(const char *name, const char *path);

/*
**	in cmd.c
*/
void			cmd(char **str, int n_env);

/*
**							BUILTINS
*/

/*
**	in ft_cd.c
*/
void			ft_cd(const char *path);

/*
**	in ft_echo.h
*/
void			ft_echo(const char **argv);

/*
**	in ft_exit.c
*/
void			ft_exit(char **argv);

/*
**	int ft_runenv.c
*/
void			ft_runenv(char **argv);

/*
**	in ft_error.c
*/
void			ft_error(const char *path, const char *str);

/*
**	in ft_free_cmd.c
*/
void			ft_free_cmd(char *path, char **av, char **env);

void			ft_putendl_free(char *str);
#endif
