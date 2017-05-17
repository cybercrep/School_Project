/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 14:00:00 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/11/11 02:51:19 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
**	in ft_
*/

/*
********************************************************************************
**							INCLUDES                                          **
********************************************************************************
*/

# include "ft_color.h"

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

/*
********************************************************************************
**							MOD                                               **
********************************************************************************
*/

/*
**		get_next_line.c
*/
# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H

#  define BUFF_SIZE 256
#  define MAX_FD_CALL 256

typedef struct	s_read
{
	int		fd;
	char	*str;
}				t_read;

int				get_next_line(const int fd, char **line);
# endif

/*
********************************************************************************
**							STRUCT                                            **
********************************************************************************
*/

# ifndef T_POINT
#  define T_POINT

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

# endif

# ifndef T_SPOINT
#  define T_SPOINT

typedef struct	s_spoint
{
	size_t	x;
	size_t	y;
}				t_spoint;

# endif

# ifndef T_INT2D
#  define T_INT2D

typedef struct	s_int2d
{
	size_t	nb_line;
	size_t	*nb_by_line;
	int		**tab;
}				t_int2d;

# endif

/*
********************************************************************************
**							FONCTIONS                                         **
********************************************************************************
*/

/*
**							IS
*/

/*
**		in ft_char_is.c
*/
int				ft_isascii(const char c);
int				ft_isalpha(const char c);
int				ft_isdigit(const char c);
int				ft_isprint(const char c);

/*
**		in ft_str_is.c
*/
int				ft_str_isalpha(const char *str);
int				ft_str_isdigit(const char *str);
int				ft_str_isin(const char *str, char c);

/*
**							PUT
*/

/*
**	in ft_put.c
*/
ssize_t			ft_putchar(const char c);
ssize_t			ft_putstr(const char *str);
ssize_t			ft_putendl(const char *str);
void			ft_putnbr(int n);

/*
**	in ft_put_fd.c
*/
ssize_t			ft_putchar_fd(const int fd, const char c);
ssize_t			ft_putstr_fd(const int fd, const char *str);
ssize_t			ft_putendl_fd(const int fd, const char *str);
void			ft_putnbr_fd(const int fd, int n);

/*
**	in ft_put_2d.c
*/
void			ft_putstr_2d(const char **str);
void			ft_putendl_2d(const char **str);

/*
**	in ft_put_2d_fd.c
*/
void			ft_putstr_2d_fd(const int fd, const char **str);

/*
**	in ft_putpoint.c
*/
void			ft_putpoint(t_point point);

/*
**	in ft_putint2d.c
*/
void			ft_putint2d(t_int2d *tab);
void			ft_putint2d_debug(t_int2d *tab);

/*
** in ft_mod_casse.c
*/
char			ft_upcasse(char c);
char			ft_downcasse(char c);

/*
**							STR
*/

/*
**	in ft_strnew.c
*/
char			*ft_strnew(size_t size);

/*
**	in ft_strdup.c
*/
char			*ft_strdup(const char *str);
char			*ft_strndup(const char *str, size_t n);

/*
**	in ft_strlen.c
*/
size_t			ft_strlen(const char *str);

/*
**	in ft_clr_str.c
*/
void			ft_strdel(char **as);
void			ft_strclr(char *str);
void			ft_strnclr(char *str, size_t n);

/*
** in ft_strcmp.c
*/
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** in ft_strequ.c
*/
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);

/*
** in ft_strcpy.c
*/
int				ft_strcpy(char *dst, const char *src);
int				ft_strncpy(char *dst, const char *src, size_t n);

/*
** in ft_strcat.c
*/
int				ft_strcat(char *dst, const char *src);
int				ft_strncat(char *dst, const char *src, size_t n);

/*
** in ft_strchr.c
*/
char			*ft_strchr(const char *str, char c);
char			*ft_strrchr(const char *str, char c);

/*
** in ft_strstr.c
*/
char			*ft_strstr(const char *meule, const char *aiguille);
char			*ft_strnstr(const char *meule, const char *aiguille, size_t n);

/*
** in ft_strsub.c
*/
char			*ft_strsub(const char *str, unsigned int start, size_t len);

/*
**	in ft_strjoin.c
*/
char			*ft_strjoin(const char *s1, const char *s2);

/*
**	in ft_strjoin_free.c
*/
char			*ft_strjoin_free(char **as, const char *s2);

/*
**	in ft_strjoinspace_2d.c
*/
char			*ft_strjoinspace_2d(const char **str);

/*
**	in ft_strintercal.c
*/
char			*ft_strintercal(const char *s1, const char c, const char *s2);

/*
**	in ft_strsplit_free.c
*/
char			**ft_strsplit_free(char **as, char c);

/*
** in ft_atoi.c
*/
int				ft_atoi(const char *str);

/*
** in ft_itoa.c
*/
char			*ft_itoa(int n);

/*
**char			*ft_strjoin_2free(char **s1, char **s2);
*/

/*
**							 STR_2D
*/

/*
** in ft_strnew_2d.c
*/
char			**ft_strnew_2d(size_t len);
void			ft_initstr_2d(char **str, size_t len);

/*
** in ft_strdel_2d.c
*/
void			ft_strdel_2d(char ***as);

/*
**							MEM
*/

/*
** in ft_memalloc.c
*/
void			*ft_memalloc(size_t size);

/*
** in ft_memdup.c
*/
void			*ft_memdup(const void *data, size_t n);

/*
** in ft_memset.c
*/
void			*ft_memset(void *b, int c, size_t len);

/*
** in ft_memdel.c
*/
void			ft_memdel(void **as);

/*
** in ft_memcmp.c
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** in ft_memcpy.c
*/
void			*ft_memcpy(void *dst, const void *src, size_t n);

/*
** in ft_memchr.c
*/
void			*ft_memchr(const void *src, int c, size_t n);

/*
**							TAB_INT
*/

/*
** in ft_new_int2d.c
*/
t_int2d			*ft_new_int2d(size_t nb_line);

/*
** in ft_gentabint.c
** int				*ft_gentabint(const char *str, size_t *nb_nbr, int i);
** need change
*/

/*
** in ft_free_int2d.c
*/
void			ft_free_int2d(t_int2d **as);

/*
**							OTHER
*/

/*
** in ft_vswap.c
*/
void			ft_vswap(void *pt_1, void *pt_2);

/*
** in ft_sizeint.c
*/
int				ft_sizeint(int n);

/*
** in ft_match.c
*/
int				ft_match(const char *s1, const char *s2);

#endif
