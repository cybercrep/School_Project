/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 02:41:07 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/21 16:07:08 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

/*
**			gestion de l'environement
*/

# define NB_ENV			2

# define NEED_STR		64
# define NEED_BUF		128

# define ENV_SET		1 + NEED_STR
# define ENV_UNSET		2 + NEED_STR
# define ENV_GET		3 + NEED_STR
# define ENV_READ		4 + NEED_BUF
# define ENV_CLEAR		5
# define ENV_SIZE		6
# define ENV_DUMP		7 + NEED_BUF

typedef struct	s_env
{
	char			*key;
	char			*valu;
	char			*all;
	struct s_env	*next;
	struct s_env	*last;
}				t_env;

/*
**			in ft_new_env.c
*/
t_env			*ft_new_env(const char *all);

/*
**			in ft_initenv.c
*/
int				ft_initenv(char **env);

/*
**			int ft_envlen.c
*/
int				ft_envlen(t_env *begin);

/*
**			in ft_env.c
*/
int				ft_envreset(t_env *env, t_env *begin);
int				ft_envset(const char *all, t_env **begin, t_env **last);
int				ft_envunset(const char *key, t_env **begin, t_env **last);
int				ft_envclear(t_env **begin, t_env **last);
int				ft_env(const char *str, t_env *buf, int key, int i);

/*
**			in ft_envget.c
*/
int				ft_envget(const char *str, t_env *begin, t_env *buf);
int				ft_envget_all(t_env *begin, t_env *buf);

/*
**			in ft_getenv.c
*/
char			*ft_getenv_valu(const char *key, int n_env);
char			*ft_getenv_all(const char *key, int n_env);
char			**ft_getenv_tab(int n_env);

/*
**			in ft_putenv.c
*/
void			ft_putenv(int i);

/*
**			in ft_envdup.c
*/
int				ft_envdump(int dst, int src);

#endif
