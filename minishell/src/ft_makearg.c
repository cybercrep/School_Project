/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makearg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 01:47:49 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/18 18:48:33 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t		len(char *line)
{
	int			bol;
	size_t		len;

	bol = 0;
	len = 0;
	while (*line)
	{
		if (*line == '\\' && *(line + 1) == '"')
			line++;
		else if (*line == '"')
		{
			bol = (bol) ? 0 : 1;
			line++;
			continue ;
		}
		else if (!bol && (*line == ' ' || *line == '\t'))
			break ;
		len++;
		line++;
	}
	return (len);
}

static char			*split(char **line, size_t len_out, int bol)
{
	char		*out;
	char		*pt_out;

	if ((out = ft_strnew(len_out)) == NULL)
		return (NULL);
	pt_out = out;
	while (**line)
	{
		if (**line == '\\' && *(*line + 1) == '"')
			(*line)++;
		else if (**line == '"')
		{
			bol = (bol) ? 0 : 1;
			(*line)++;
			continue ;
		}
		else if (!bol && (**line == ' ' || **line == '\t'))
			break ;
		*pt_out = **line;
		pt_out++;
		(*line)++;
	}
	*pt_out = '\0';
	return (out);
}

static	char		*take_home(char *tmp)
{
	char		*out;
	t_env		buf;

	if (ft_env("HOME", &buf, ENV_GET, 0) == -1)
	{
		ft_putstr_fd(2, "fail get HOME\n");
		return (NULL);
	}
	if ((out = ft_strjoin(buf.valu, &tmp[1])) == NULL)
		return (NULL);
	free(tmp);
	return (out);
}

char				**ft_makearg(char *line, int i)
{
	char				*tmp;
	char				**out;

	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '\0' && i == 0)
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	tmp = split(&line, len(line), 0);
	if (tmp[0] == '~')
		if ((tmp = take_home(tmp)) == NULL)
			return (NULL);
	if (*line == '\0')
		if ((out = ft_strnew_2d(i + 1)) == NULL)
			return (NULL);
	if (*line == '\0')
		out[i] = NULL;
	else if ((out = ft_makearg(line, i + 1)) == NULL)
		return (NULL);
	if (tmp[0] == '\0')
		ft_strdel(&tmp);
	out[i] = tmp;
	return (out);
}
