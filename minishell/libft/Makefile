# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/21 00:01:29 by tifuzeau          #+#    #+#              #
#    Updated: 2016/10/28 13:59:27 by tifuzeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
VERSION	= 1.0.1
DEBUG	= no

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

INC_PATH= ./includes/
OBJ_PATH= ./obj/
SRC_PATH= ./src/

# **************************************************************************** #
#									NAME                                       #
# **************************************************************************** #

OBJ_NAME= $(SRC_NAME:.c=.o)
SRC_NAME=ft_char_is.c ft_str_is.c ft_mod_casse.c\
		  \
		  ft_put.c ft_put_fd.c ft_put_2d.c ft_put_2d_fd.c ft_putpoint.c \
		  ft_putint2d.c\
		  \
		  ft_strnew.c ft_strdup.c ft_strlen.c ft_clr_str.c ft_strcmp.c \
		  ft_strequ.c ft_strcpy.c ft_strcat.c ft_strchr.c ft_strstr.c \
		  ft_strsub.c ft_strjoin.c ft_strjoin_free.c ft_strjoinspace_2d.c \
		  ft_strintercal.c ft_strsplit_free.c \
		  ft_atoi.c ft_itoa.c\
		  \
		  ft_strnew_2d.c ft_strdel_2d.c\
		  \
		  ft_memalloc.c ft_memdup.c ft_memset.c ft_memdel.c ft_memcmp.c \
		  ft_memcpy.c ft_memchr.c\
		  \
		  ft_new_int2d.c ft_free_int2d.c\
		  \
		  ft_vswap.c ft_sizeint.c ft_match.c\
		  \
		  get_next_line.c\
		  \
		  ft_putcolor.c

# **************************************************************************** #
#									VAR                                        #
# **************************************************************************** #

INC		= $(addprefix -I,$(INC_PATH))
OBJ		= $(addprefix $(OBJ_PATH),$(OBJ_NAME))
SRC		= $(addprefix $(SRC_PATH),$(SRC_NAME))

# **************************************************************************** #
#									SHELL                                      #
# **************************************************************************** #

CC		= gcc
AR		= ar
RM		= rm

# **************************************************************************** #
#									FLAG                                       #
# **************************************************************************** #

ifndef CC_FLAG
	CC_FLAG	= -Wall -Werror -Wextra -o3
endif
AR_FLAG	= rcs

# **************************************************************************** #
#									STR IN COLOR                               #
# **************************************************************************** #

OK		= "\033[0;33mOK\033[0;0m\n"

# **************************************************************************** #
#									REGLES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@printf "Creation de $(NAME):"
	@$(AR) $(AR_FLAG) $(NAME) $(OBJ)
	@printf $(OK)

$(OBJ_PATH):
	@printf "Creation de $(OBJ_PATH):"
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@printf $(OK)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "Creation de $@:"
	@$(CC) $(CC_FLAG) $(LIB) $(INC) -o $@ -c $<
	@printf " done\n"

clean:
	@printf "Clean des obj:"
	@$(RM) -f $(OBJ)
	@printf " done\n"
	@printf "Clean $(OBJ_PATH):"
	@$(RM) -rf $(OBJ_PATH) 2> /dev/null
	@printf " done\n"

fclean: clean
	@printf "Clean $(NAME):"
	@$(RM) -f $(NAME)
	@printf " done\n"

re: fclean all

norme:
	@printf "\tNorme de $(SRC)\n"
	@norminette $(SRC)
	@printf "\tNorme de $(INC_PATH)\n"
	@norminette $(INC_PATH)

version:
	@printf "$(NAME)_$(VERSION)\n"
