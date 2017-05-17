/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 22:27:58 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/09/11 23:32:05 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_match(const char *s1, const char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	if (*s1 == *s2)
		return (ft_match(s1 + 1, s2 + 1));
	if (!*s1 && *s2 == '*')
		return (ft_match(s1, s2 + 1));
	if (*s1 && *s2 == '*')
		return (ft_match(s1 + 1, s2) || ft_match(s1, s2 + 1));
	return (0);
}
