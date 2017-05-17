/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 14:00:00 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/07 21:31:28 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

# include "get_next_line.h"

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

int				ft_isascii(const char c);
int				ft_isalpha(const char c);
int				ft_isdigit(const char c);
int				ft_isprint(const char c);

void			ft_vswap(void *pt_1, void *pt_2);

int				ft_str_isalpha(const char *str);
int				ft_str_isdigit(const char *str);

char			ft_upcasse(char c);
char			ft_downcasse(char c);

void			ft_putchar(char c);
void			ft_putchar_fd(const int fd, char c);

void			ft_putnbr(int n);
void			ft_putnbr_fd(const int fd, int c);

ssize_t			ft_putstr(const char *str);
ssize_t			ft_putstr_fd(const int fd, const char *str);

void			ft_puterror(const char *str);
void			ft_putendl(const char *str);
void			ft_putendl_fd(const int fd, const char *str);

void			ft_putstr_2d(const char **str);
void			ft_putstr_2d_fd(const int fd, const char **str);

void			ft_putendl_2d(const char **str);

char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *str);

char			*ft_strdup(const char *str);
char			*ft_strndup(const char *str, size_t n);

void			ft_strclr(char *str);
void			ft_strnclr(char *str, size_t n);
void			ft_strdel(char **as);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);

int				ft_strcat(char *dst, const char *src);
int				ft_strncat(char *dst, const char *src, size_t n);

int				ft_strcpy(char *dst, const char *src);
int				ft_strncpy(char *dst, const char *src, size_t n);

char			*ft_strchr(const char *str, char c);
char			*ft_strrchr(const char *str, char c);

char			*ft_strstr(const char *meule, const char *aiguille);
char			*ft_strnstr(const char *meule, const char *aiguille, size_t n);

char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoin_free(char **as, const char *s2);
char			*ft_strjoin_2free(char **s1, char **s2);

char			*ft_strsub(const char *str, unsigned int start, size_t len);

int				*ft_gentabint(const char *str, size_t *nb_nbr, int i);

char			**ft_strnew_2d(size_t len);
void			ft_initstr_2d(char **str, size_t len);

void			ft_strdel_2d(char ***as);

void			*ft_memalloc(size_t size);
void			*ft_memdup(const void *data, size_t n);

void			ft_memdel(void **as);

void			*ft_memset(void *b, int c, size_t len);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memchr(const void *src, int c, size_t n);

int				ft_atoi(const char *str);

char			*ft_itoa(int n);

int				ft_sizeint(int n);

void			ft_putpoint(t_point point);

t_int2d			*ft_new_int2d(size_t nb_line);
void			ft_free_int2d(t_int2d **as);

void			ft_putint2d(t_int2d *tab);
void			ft_putint2d_debug(t_int2d *tab);

#endif
