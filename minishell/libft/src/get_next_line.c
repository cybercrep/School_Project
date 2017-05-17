/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 05:16:58 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/28 13:57:21 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*read_and_write(const int fd, char *buf,
		t_read *last, int bol)
{
	char	*tmp;

	if (bol == 0)
	{
		tmp = last->str;
		ft_strcpy(buf, last->str);
		free(last->str);
		last->str = NULL;
		last->fd = -1;
	}
	else
	{
		last->fd = fd;
		tmp = ft_strchr(buf, '\n');
		if ((last->str = ft_strdup(tmp + 1)) == NULL)
			return (NULL);
		if ((tmp = ft_strndup(buf, (tmp - buf))) == NULL)
			return (NULL);
		free(buf);
	}
	return (tmp);
}

static char			*last(int const fd, char *buf, int bol)
{
	size_t			i;
	char			*tmp;
	static t_read	*last[MAX_FD_CALL + 1] = { NULL};

	tmp = buf;
	i = 0;
	if (bol == 0)
	{
		while (last[i] && last[i]->fd != fd && i != MAX_FD_CALL)
			i++;
		if (last[i] && i != MAX_FD_CALL)
			read_and_write(fd, buf, last[i], 0);
	}
	else if (ft_str_isin(buf, '\n') == 1)
	{
		while (last[i] && last[i]->fd != -1 && i != MAX_FD_CALL)
			i++;
		if (last[i] == NULL)
			if ((last[i] = (t_read *)malloc(sizeof(t_read))) == NULL)
				return (NULL);
		tmp = read_and_write(fd, buf, last[i], 1);
	}
	if (i == MAX_FD_CALL)
		return (NULL);
	return (tmp);
}

static int			chek_line(const int fd, int ret, char **line)
{
	if ((*line = last(fd, *line, 1)) == NULL || ret == -1)
	{
		if (*line != NULL)
			ft_strdel(line);
		return (-1);
	}
	if (ret == 0 && **line == '\0')
	{
		ft_strdel(line);
		return (0);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];

	ret = 1;
	ft_strnclr(buf, BUFF_SIZE + 1);
	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	last(fd, buf, 0);
	while ((*line = ft_strjoin_free(&*line, buf)) != NULL)
	{
		if (ft_str_isin(buf, '\n') == 1 || ret == 0)
			break ;
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			break ;
		buf[ret] = '\0';
	}
	return (chek_line(fd, ret, line));
}
