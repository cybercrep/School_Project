/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:57:25 by tifuzeau          #+#    #+#             */
/*   Updated: 2016/10/31 17:17:47 by tifuzeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include "libft.h"

void		ft_putcolor(const char *str, const char *color);

# define C_RESET	"\033[0m"

/*
**				Regular Colors
*/
# define C_BLACK	"\033[0;30m"
# define C_RED		"\033[0;31m"
# define C_GREEN	"\033[0;32m"
# define C_YELLOW	"\033[0;33m"
# define C_BLUE		"\033[0;34m"
# define C_PURPLE	"\033[0;35m"
# define C_CYAN		"\033[0;36m"
# define C_WHITE	"\033[0;37m"

/*
**				Blod Colors
*/
# define C_BBLACK	"\033[1;30m"
# define C_BRED		"\033[1;31m"
# define C_BGREEN	"\033[1;32m"
# define C_BYELLOW	"\033[1;33m"
# define C_BBLUE	"\033[1;34m"
# define C_BPURPLE	"\033[1;35m"
# define C_BCYAN	"\033[1;36m"
# define C_BWHITE	"\033[1;37m"

/*
**				Underline Colors
*/
# define C_UBLACK	"\033[1;30m"
# define C_URED		"\033[1;31m"
# define C_UGREEN	"\033[1;32m"
# define C_UYELLOW	"\033[1;33m"
# define C_UBLUE	"\033[1;34m"
# define C_UPURPLE	"\033[1;35m"
# define C_UCYAN	"\033[1;36m"
# define C_UWHITE	"\033[1;37m"

#endif
