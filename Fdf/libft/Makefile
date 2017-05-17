# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/21 00:01:29 by tifuzeau          #+#    #+#              #
#    Updated: 2016/09/07 21:31:51 by tifuzeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

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
SRC_NAME= ft_strnew.c ft_strlen.c\
		  ft_strdup.c ft_strndup.c\
		  ft_vswap.c\
		  ft_isascii.c ft_isalpha.c ft_isdigit.c ft_isprint.c\
		  ft_str_isalpha.c ft_str_isdigit.c\
		  ft_puterror.c ft_putchar.c ft_putchar_fd.c ft_putnbr.c ft_putnbr_fd.c\
		  ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c\
		  ft_putstr_2d.c ft_putstr_2d_fd.c ft_putendl_2d.c\
		  ft_upcasse.c ft_downcasse.c\
		  ft_strclr.c ft_strnclr.c ft_strdel.c\
		  ft_strcmp.c ft_strncmp.c ft_strequ.c ft_strnequ.c\
		  ft_strcat.c ft_strncat.c ft_strcpy.c ft_strncpy.c\
		  ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c\
		  ft_strjoin.c ft_strjoin_free.c ft_strjoin_2free.c ft_strsub.c\
		  ft_strnew_2d.c ft_initstr_2d.c\
		  ft_strdel_2d.c\
		  ft_memalloc.c ft_memdup.c ft_memdel.c ft_memset.c ft_memset.c\
		  ft_memcmp.c ft_memcpy.c ft_memchr.c\
		  ft_atoi.c ft_itoa.c\
		  ft_sizeint.c get_next_line.c\
		  ft_putpoint.c\
		  ft_gentabint.c ft_new_int2d.c ft_putint2d.c ft_free_int2d.c


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

CC_FLAG	= -Wall -Werror -Wextra -o3
AR_FLAG	= rcs

# **************************************************************************** #
#									STR IN COLOR                               #
# **************************************************************************** #

OK		= "\033[0;33mOK\033[0;0m\n"

# **************************************************************************** #
#									REGLES                                     #
# **************************************************************************** #

all: $(NAME)
	@printf "\n"

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
