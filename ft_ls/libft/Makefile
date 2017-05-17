# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/21 00:01:29 by tifuzeau          #+#    #+#              #
#    Updated: 2016/06/29 05:33:31 by tifuzeau         ###   ########.fr        #
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
SRC_NAME= ft_strjoin_free.c ft_strlen.c ft_strnew.c ft_strcpy.c ft_strcat.c \
		  ft_strjoin.c ft_strdup.c ft_strcmp.c ft_strdel.c ft_strintercal.c \
		  ft_swap.c ft_strintercal.c ft_strjoin_2free.c ft_strsub.c \
		  ft_strndup.c ft_strjoin_free.c ft_dim_x.c ft_initstr_2d.c \
		  ft_strsplit_free.c ft_putendl.c ft_inittab_size_t.c \
		  ft_size_t_addtab.c ft_strjoin_one_size.c ft_free_2d_size.c \
		  ft_free_2d.c ft_strsplit_tmp.c ft_putstr_2d.c ft_putendl_2d.c \
		  ft_strnew_2d.c ft_itoa.c ft_putstr.c ft_itoa_size_t.c


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
	@norminette $(SRC)
