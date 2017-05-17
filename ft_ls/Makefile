# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tifuzeau <tifuzeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/28 14:00:16 by tifuzeau          #+#    #+#              #
#    Updated: 2016/06/29 05:33:03 by tifuzeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

LIB_PATH= ./libft/
INC_PATH= ./includes/
OBJ_PATH= ./obj/
SRC_PATH= ./src/

# **************************************************************************** #
#									NAME                                       #
# **************************************************************************** #

LIB_NAME= libft
OBJ_NAME= $(SRC_NAME:.c=.o)
SRC_NAME= main.c fail.c flag.c lest_go.c inser.c init.c read_dir.c recursive.c \
		  new_2lst_info.c reverse_2lst.c del_2lst_info.c loop_2lst.c \
		  print_name.c parseur.c putpath.c print_usage.c \
		  print_list.c make_str_list.c make_right.c make_usr_grp.c \
		  make_oc_mi_maj.c make_time.c make_size_l.c itoa_off_t.c make_link.c \
		  itoa_nlink_t.c make_name_link.c print_one.c print.c

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

CC_FLAG	= -Wall -Werror -Wextra -O3

# **************************************************************************** #
#									COLOR STR VAR                              #
# **************************************************************************** #

START	=\033[0;32mStart\033[0m\n
END		=\033[0;32mEnd\033[0;0m\n\n
OK		=\033[0;33mOK\033[0;0m\n\n

# **************************************************************************** #
#									REGLE                                      #
# **************************************************************************** #
#-fsanitize=address  flag to debug

all: $(LIB_SRC) $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ)
	@printf "Creation de $(NAME):"
	@$(CC) $(LIB_SRC) $^ -o $@
	@printf " $(OK)"

$(LIB_SRC): $(LIB_PATH)
	@printf "Creation de $(LIB_NAME).a: $(START)"
	@make -C $(LIB_PATH) all
	@printf "Creation de $(LIB_NAME).a: $(END)"

$(OBJ_PATH):
	@printf "Creation de $(OBJ_PATH):"
	@mkdir -p $(OBJ_PATH) 2> /dev/null 
	@printf " $(OK)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
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
	@printf "Clean $(OBJ_PATH):"
	@rm -rf $(OBJ_PATH) 2> /dev/null
	@printf " done\n\n"

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
