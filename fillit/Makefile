# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/28 14:00:16 by tifuzeau          #+#    #+#              #
#    Updated: 2018/01/15 22:47:01 by timfuzea    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

PWD			:= $(shell pwd)

LIB_PATH= ./libft/
INC_PATH= $(PWD)/
OBJ_PATH= $(PWD)/
SRC_PATH= $(PWD)/

# **************************************************************************** #
#									NAME                                       #
# **************************************************************************** #

LIB_NAME= libft
OBJ_NAME= $(SRC_NAME:.c=.o)
SRC_NAME=  algo.c error.c get.c init.c \
		   main.c putmap.c read_input.c reste.c shift_bit.c


# **************************************************************************** #
#									VAR                                        #
# **************************************************************************** #

LIB_SRC = $(addprefix $(LIB_PATH),$(LIB_NAME).a)
INC		= $(addprefix -I,$(INC_PATH))
SRC		= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ		= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# **************************************************************************** #
#									SHELL                                      #
# **************************************************************************** #

CC		= gcc

# **************************************************************************** #
#									FLAGS                                      #
# **************************************************************************** #

CC_FLAG	= -Wall -Werror -Wextra

# **************************************************************************** #
#									COLOR STR VAR                              #
# **************************************************************************** #

START	=\033[0;32mStart\033[0m\n
END		=\033[0;32mEnd\033[0;0m\n\n
OK		=\033[0;33mOK\033[0;0m\n\n

# **************************************************************************** #
#									REGLE                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): creat_ft $(OBJ_PATH) $(OBJ)
	@printf "Creation de $(NAME):"
	@$(CC) $(LIB_SRC) $(OBJ) -o $@
	@printf " $(OK)"

creat_ft: $(LIB_PATH)
	@printf "Creation de $(LIB_NAME).a: $(START)"
	@make -C $(LIB_PATH) all
	@printf "Creation de $(LIB_NAME).a: $(END)"

$(OBJ_PATH):
	@printf "Creation de $(OBJ_PATH):"
	@mkdir -p $(OBJ_PATH) 2> /dev/null 
	@printf " $(OK)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH)
	@printf "Creation de $@:"
	@$(CC) $(CC_FLAG) $(INC) -o $@ -c $< 
	@printf " done\n"

clean:
	@printf "Clean $(LIB_NAME): $(START)"
	@make -C $(LIB_PATH) clean
	@printf "Clean $(LIB_PATH): $(END)"
	@printf "Clean des obj:"
	@rm -f $(OBJ)
	@printf " done\n"

fclean: clean
	@printf "Fclean $(LIB_NAME): $(START)"
	@make -C $(LIB_PATH) fclean
	@printf "Fclean $(LIB_NAME): $(END)"
	@printf "Clean de $(NAME):"
	@rm -rf $(NAME)
	@printf " $(OK)"

re: fclean all

norme:
	@printf "Norme de $(LIB_PATH): $(START)"
	@make -C $(LIB_PATH) norme
	@printf "Norme de $(LIB_PATH): $(END)"
	@norminette $(SRC)
