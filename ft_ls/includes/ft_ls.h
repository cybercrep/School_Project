/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 14:13:11 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/29 05:00:36 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define USAGE "usage: ft_ls [-Ralrt] [file ...]\n"

# define ARG_L		1
# define ARG_A		2
# define ARG_R		4
# define ARG_RR		8
# define ARG_T		16

unsigned int g_flag;

# define T_STAT struct stat

# define MAX_ELEM	10

# define L_PRINT	0
# define L_RIGHT	1
# define L_LINK		2
# define L_USR		3
# define L_GRP		4
# define L_OC		5
# define L_MON		6
# define L_DATE		7
# define L_HO_YE	8
# define L_NAME		9

# define BUFF_LNK	512

# define MINORBITS	20
# define MINORMASK	((1 << MINORBITS) - 1)

# define MAJOR(dev) ((unsigned int) ((dev) >> (MINORBITS + 4)))
# define MINOR(dev) ((unsigned int) ((dev) & MINORMASK))

typedef struct		s_2lst_info
{
	char					*path;
	char					*print_l[MAX_ELEM + 1];
	size_t					size_l[MAX_ELEM + 1];
	T_STAT					st_info;
	struct dirent			*info_dir;
	struct passwd			*info_pass;
	struct group			*info_grp;
	struct s_2lst_info		*next;
	struct s_2lst_info		*last;
}					t_2lst_info;

t_2lst_info			*parseur(int argc, const char *argv[]);
t_2lst_info			*read_dir(DIR *fd_dir, const char *path);

void				print_name(t_2lst_info *lst);
void				print_usage(char c);
int					lest_go(char *path);

void				fail(const char *str);
void				recursive(char *path, t_2lst_info *begin_lst);
void				putpath(const char *str);

int					flag(const char *str);

void				print(t_2lst_info *begin_lst, int bol);

void				del_2lst_info(t_2lst_info **as);
void				loop_2lst(t_2lst_info *lst);
void				reverse_2lst(t_2lst_info **begin_lst);
t_2lst_info			*new_2lst_info(void);

void				inser(t_2lst_info **begin_lst,
		t_2lst_info *a_placer, int(*foo)());

int					dir_cmp(t_2lst_info *ref, t_2lst_info *cmp);
int					time_cmp(t_2lst_info *ref, t_2lst_info *cmp);
int					alpha_cmp(t_2lst_info *ref, t_2lst_info *cmp);

char				*init_droit(void);

void				print_list(t_2lst_info *begin_lst);

char				*make_str_list(t_2lst_info *begin_lst);
int					make_right(t_2lst_info *mallion);
int					make_link(t_2lst_info *mallion);
int					make_usr_grp(t_2lst_info *mallion);
int					make_size_oc(t_2lst_info *mallion);
int					make_time(t_2lst_info *mallion);
int					make_name_link(t_2lst_info *mallion);

void				print_one(t_2lst_info *lst);
void				make_size_l(t_2lst_info *mallion);

char				*itoa_off_t(off_t nbr);
char				*itoa_nlink_t(nlink_t n);
#endif
