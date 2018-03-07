/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 22:54:42 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 21:45:32 by legrivel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 675
# define MAX_PIECES 26
# define SHOW_ERROR 0
# define SHOW_DEBUG 0

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define S 0xCC0000
# define IH 0xF00000
# define IV 0x888800
# define SH 0x8C4000
# define SV 0x6C0000
# define ZH 0x4C8000
# define ZV 0xC60000
# define TU 0xE40000
# define TD 0x4E0000
# define TL 0x8C8000
# define TR 0x4C4000
# define JU 0xC44000
# define JD 0x44C000
# define JL 0xE80000
# define JR 0xE20000
# define LU 0x88C000
# define LD 0xC88000
# define LL 0x2E0000
# define LR 0x8E0000

# ifndef T_POINT
#  define T_POINT

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

# endif

typedef struct		s_square
{
	int				nbr_pieces;
	int				size_mini;
	unsigned int	*pieces;
}					t_square;

t_square			*init_map(unsigned int *pieces, int nbr_pieces);
t_point				*init_pos_tab(int nbr_pieces);
char				**inittab(int sq_size);

void				error(char *error_msg);

unsigned int		shift_to_upperleft(unsigned int pieces);
unsigned int		get_pieces_from_raw(char buf[21]);
int					read_input(int fd, unsigned int pieces[MAX_PIECES + 1]);

unsigned int		shift_up(unsigned int pieces);
unsigned int		shift_down(unsigned int pieces);
unsigned int		shift_left(unsigned int pieces);
unsigned int		shift_right(unsigned int pieces);
unsigned int		shift_by(unsigned int pieces, t_point pos);

void				reset_pos_tab(t_point *pos_tab, int begin, int nbr_pieces);

int					solve(t_square *map, t_point *pos_tab,
						int num_pieces, int skip);
int					put_pieces(t_square *map, t_point *pos_tab,
						int num_pieces, int skip);
int					collides(t_square *map, unsigned int pieces,
						t_point pos, t_point *pos_tab);

unsigned int		get_map_from(t_square *map, t_point pos, t_point *pos_tab);
int					get_square_size(t_square *map, t_point *pos_tab);

void				putmap(char **tab);
char				**filltab(char **tab, t_square *map, t_point *pos_tab);

#endif
