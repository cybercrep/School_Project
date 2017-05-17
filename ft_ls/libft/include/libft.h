/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:13:49 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/06/24 05:02:54 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

char		*ft_strdup(const char *str);
char		*ft_strndup(const char *str, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin_free(char **as, const char *s2);
char		*ft_strjoin_2free(char **s1, char **s2);
char		*ft_strintercal(const char *s1, const char c, const char *s2);
char		*ft_strsub(const char *s, unsigned int start, size_t len);
char		*ft_strjoin_one_size(const char **str,
		size_t *max_size, size_t size);
char		*ft_itoa_size_t(size_t n);
char		*ft_itoa(int n);

char		**ft_strnew_2d(size_t len);
char		**ft_strsplit(const char *str, char c);
char		**ft_strsplit_free(char **as, char c);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_sizeint(int n);

size_t		ft_strcpy(char *dst, const char *src);
size_t		ft_strlen(const char *str);
size_t		ft_dim_x(const char *s, char c);
size_t		ft_size_t_addtab(const size_t *tab, size_t len);

void		ft_strdel(char **as);
void		ft_free_2d(char **str);
void		ft_free_2d_size(char **str, size_t len);
void		ft_swap(void *a, void *b);

void		ft_putstr(const char *str);
void		ft_putendl(const char *str);
void		ft_putendl_2d(const char **str);
void		ft_putstr_2d(const char **str);

void		ft_initstr_2d(char **str, size_t len);
void		ft_inittab_size_t(size_t *tab, size_t len);
#endif
