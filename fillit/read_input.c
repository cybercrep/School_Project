/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_input.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 22:54:11 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 22:54:11 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	shift_to_upperleft(unsigned int pieces)
{
	int			x;
	int			y;
	int			xmin;
	int			ymin;
	t_point		pos;

	y = -1;
	xmin = 4;
	ymin = 4;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if ((1 << (-x - 4 * y + 23)) & pieces)
			{
				xmin = x < xmin ? x : xmin;
				ymin = y < ymin ? y : ymin;
			}
		}
	}
	pos.x = xmin;
	pos.y = ymin;
	return (shift_by(pieces, pos));
}

unsigned int	valide_pieces(unsigned int p)
{
	if (!(p == S
		|| p == IH || p == IV
		|| p == SH || p == SV
		|| p == ZH || p == ZV
		|| p == TU || p == TD || p == TL || p == TR
		|| p == JU || p == JD || p == JL || p == JR
		|| p == LU || p == LD || p == LL || p == LR))
		error("unvalide pieces");
	return (p);
}

unsigned int	get_pieces_from_raw(char buf[21])
{
	int			i;
	int			pos;
	int			pieces;

	i = 0;
	pos = 0;
	pieces = 0;
	while ((pos / 5) < 4)
	{
		while ((pos % 5) < 4)
		{
			if (buf[pos] != '#' && buf[pos] != '.')
				error("found unxpeted char");
			pieces += buf[pos] == '#' ? 1 : 0;
			i += buf[pos] == '#' ? 1 : 0;
			pieces <<= 1;
			pos++;
		}
		if (buf[pos++] != '\n')
			error("map error no newline");
	}
	if (i != 4)
		error("unvalide tetriminos not 4 case");
	return (valide_pieces(shift_to_upperleft(pieces << 7)));
}

int				read_input(int fd, unsigned int pieces[MAX_PIECES + 1])
{
	int			ret;
	int			one_more;
	int			nbr_pieces;
	char		buf[21];

	nbr_pieces = 0;
	while ((ret = read(fd, buf, 20)))
	{
		one_more = 0;
		if (ret != 20)
			error("read fail or map error");
		buf[20] = '\0';
		if ((pieces[nbr_pieces] = get_pieces_from_raw(buf)) == 0)
			error("fail to make pieces");
		nbr_pieces++;
		if (read(fd, buf, 1) != 1)
			break ;
		if (buf[0] != '\n' || nbr_pieces > MAX_PIECES)
			error("to many pieces of map error");
		one_more = 1;
	}
	if (one_more)
		error("newline at end of file");
	pieces[nbr_pieces] = 0;
	return (nbr_pieces);
}
